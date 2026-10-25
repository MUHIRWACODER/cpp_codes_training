#include<iostream>
using namespace std;
int main(){
    int number,first_digit,last_digit;
    cout<<"Enter a number"<<endl;
    cin>>number;
    last_digit=number%10;
    while(number !=0){
        first_digit=number%10;
        number=number/10;
    }
    cout<<"The first digit of the number is :"<<first_digit<<endl;
    cout<<"The last digit of the number is :"<<last_digit<<endl;
    return 0;
}