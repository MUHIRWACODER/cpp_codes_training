#include<iostream>
using namespace std;
int main(){
    double n1,n2;
    char ch;
    cout <<"Enter the first number"<<endl;
    cin>>n1;
    cout<<"Enter the second number"<<endl;
    cin>>n2;
    cout<<"Enter the operation you want to perform (+,-,*,/)"<<endl;
    cin>>ch;
    switch(ch){
        case '+':
        cout<<"The sum of "<<n1<<" and "<<n2<<" is :"<<n1+n2;
        break;
        case '-':
        cout<<"The difference of "<<n1<<" and "<<n2<<" is :"<<n1-n2;
        break;
        case '*':
        cout<<"The product of "<<n1<<" and "<<n2<<" is :"<<n1*n2;
        break;
        case '/':
        if(n2==0){
            cout<<"Division by zero is not allowed"<<endl;
        }
        else{
            cout<<"The quotient of "<<n1<<" and "<<n2<<" is :"<<n1/n2;
        }
        break;
    
 
    default:
        cout<<"Invalid operation"<<endl;}

        return 0;
}