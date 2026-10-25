#include<iostream>
using namespace std;
void area (int *h, int *w){
    int ar= *h * *w;
    cout<<"The area of the rectangle is :"<<ar;

}
int main(){
    int x,y;
    cout<<"Enter the height of the rectangle"<<endl;
    cin>>x;
    cout<<"Enter the width of the rectangle"<<endl;
    cin>>y;
    area(&x,&y);
    return 0;
}