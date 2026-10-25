#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Define a structure to hold employee information neatly
struct Employee {
    int id;
    string name;
    string position;
    double salary;
};

int main() {
    // Open a text file in append mode (ios::app) 
    // This ensures new records are added to the bottom without erasing old ones.
    ofstream outFile("employees.txt", ios::app);

    // Check if the file opened successfully
    if (!outFile) {
        cout << "Error: Could not open file for writing!" << endl;
        return 1;
    }

    char choice;
    cout << "=== Employee Data Management System ===" << endl;

    // Use a do-while loop because we don't know how many employees will be added
    do {
        Employee emp;

        cout << "\nEnter Employee ID: ";
        cin >> emp.id;

        // Clear the input buffer to prevent getline() from skipping input 
        // because of the leftover newline character from cin >>
        cin.ignore();

        cout << "Enter Employee Full Name: ";
        getline(cin, emp.name);

        cout << "Enter Job Position: ";
        getline(cin, emp.position);

        cout << "Enter Salary: ";
        cin >> emp.salary;

        // Write the structured data directly into the text file
        outFile << "ID: " << emp.id 
                << " | Name: " << emp.name 
                << " | Position: " << emp.position 
                << " | Salary: RWF" << emp.salary << endl;

        cout << "Record saved successfully!" << endl;

        // Ask the user if they want to continue entering data
        cout << "\nDo you want to add another employee? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    // Always remember to close your file stream when finished
    outFile.close();
    
    cout << "\nAll records have been saved to 'employees.txt'. Goodbye!" << endl;

    return 0;
}