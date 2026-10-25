#include<iostream>
using namespace std;
int main(){
    int n1,n2,m=1;
    cout<<"enter the first number"<<endl;
    cin>>n1;
    cout <<"enter the second number "<<endl;
    cin>>n2;
    for(int i=1;i<=n1;i++){
        if(n1%i==0 && n2%i==0){
            m=i;
        }

    }
    cout<<"HCF of "<<n1 <<"and "<<n2<<"is "<<m;
    
}