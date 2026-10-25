#include<iostream>
using namespace std;
int main(){
    int number, b;
    cout<<"Enter a number"<<endl;
    cin>>number;
    cout<<"The reverse of the digits of the number is :";
    while(number !=0){
        b=number%10;
        cout<<b;
        number=number/10;
    }
    return 0;
}