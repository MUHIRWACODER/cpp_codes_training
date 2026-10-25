#include<iostream>
using namespace std;
int main(){
    int n1,n2,m=1;
    cout<<"enter the first number"<<endl;
    cin>>n1;
    cout <<"enter the second number"<<endl;
    cin>>n2;
    for (int i=n1;;i++){
        if (i%n1==0 && i%n2==0){
            m=i;
            break;
        }

    }
    cout<<"lcm of "<<n1 <<"and "<<n2<<"is :"<<m;
}