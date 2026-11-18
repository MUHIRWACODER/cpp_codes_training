#include <iostream>
#include <limits> // Used for clearing invalid inputs

using namespace std;

// Global constant for the board size
const int BOARD_SIZE = 3;

// --- Function Prototypes ---
void displayBoard(char board[]);
bool isValidMove(char board[], int position);
void updateBoard(char board[], int position, char player);
char checkWinner(char board[]);
bool isBoardFull(char board[]);
void clearInputBuffer();
void resetBoard(char board[]);

int main() {
    char board[9]; // Array to represent the 3x3 grid (indices 0-8)
    char currentPlayer = 'X';
    char playAgain = 'y';

    do {
        resetBoard(board);
        currentPlayer = 'X'; // X always starts
        bool gameOver = false;
        char winner = ' ';

        cout << "\n=== Welcome to Tic-Tac-Toe ===\n";

        // Main Game Loop
        while (!gameOver) {
            displayBoard(board);
            int move;
            bool validMove = false;

            // Input Validation Loop
            while (!validMove) {
                cout << "Player " << currentPlayer << ", enter a position (1-9): ";
                
                // Check if the input is an integer
                if (!(cin >> move)) {
                    cout << "Invalid input! Please enter a number.\n";
                    clearInputBuffer();
                    continue;
                }

                // Check if the move is between 1 and 9
                if (move < 1 || move > 9) {
                    cout << "Invalid position! Choose a number between 1 and 9.\n";
                } 
                // Check if the spot is already taken
                else if (!isValidMove(board, move - 1)) { 
                    cout << "That spot is already taken! Try again.\n";
                } 
                else {
                    validMove = true;
                    // Update the board (subtract 1 from move to match array index 0-8)
                    updateBoard(board, move - 1, currentPlayer);
                }
            }

            // Check for a winner after the move
            winner = checkWinner(board);

            if (winner != ' ') {
                displayBoard(board);
                cout << "\n*** Congratulations! Player " << winner << " wins! ***\n";
                gameOver = true;
            } 
            // Check for a draw
            else if (isBoardFull(board)) {
                displayBoard(board);
                cout << "\n*** It's a draw! Nobody wins. ***\n";
                gameOver = true;
            } 
            // Switch player if game continues
            else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }

        // Ask to play again
        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}

// Function to draw the board on the screen
void displayBoard(char board[]) {
    cout << "\n";
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << "\n";
    cout << "\n";
}

// Function to check if a chosen spot is empty
bool isValidMove(char board[], int position) {
    // If the spot is not 'X' or 'O', it must be a number (empty)
    return (board[position] != 'X' && board[position] != 'O');
}

// Function to place the player's mark on the board
void updateBoard(char board[], int position, char player) {
    board[position] = player;
}

// Function to check all win conditions
char checkWinner(char board[]) {
    // 8 Winning combinations: 3 rows, 3 columns, 2 diagonals
    int winCombos[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
        {0, 4, 8}, {2, 4, 6}             // Diagonals
    };

    // Loop through all combinations to see if someone has 3 in a row
    for (int i = 0; i < 8; i++) {
        int a = winCombos[i][0];
        int b = winCombos[i][1];
        int c = winCombos[i][2];

        // If the three spots are the same and not a number (empty)
        if (board[a] == board[b] && board[b] == board[c] && board[a] != ' ') {
            // Safety check to ensure it's not matching against an empty number slot
            if(board[a] == 'X' || board[a] == 'O') {
                return board[a]; // Returns 'X' or 'O'
            }
        }
    }
    return ' '; // No winner yet
}

// Function to check if the board is completely full (Draw condition)
bool isBoardFull(char board[]) {
    for (int i = 0; i < 9; i++) {
        // If we find a spot that is neither X nor O, it's not full
        if (board[i] != 'X' && board[i] != 'O') {
            return false;
        }
    }
    return true; // All spots are filled
}

// Helper function to clear the input buffer if the user types a letter instead of a number
void clearInputBuffer() {
    cin.clear(); // Clear the error flag
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the bad input
}

// Function to reset the board to numbers 1-9 for a new game
void resetBoard(char board[]) {
    for (int i = 0; i < 9; i++) {
        // '1' + i converts the index (0-8) to characters ('1'-'9')
        board[i] = '1' + i; 
    }
}