#include<iostream>
using namespace std;
int glo = 6;
void sum(){
    cout<<glo;
}
int main()
{
    sum();
    int glo = 6;
    glo = 78;
    cout<<"\n"<<glo;
    // int a = 4, b = 5;
    // cout<<"This is tutorial4.\nThe value of a is "<<a<<".\nThe value of b is "<<b<<".\n";
    // float pi = 3.14;
    // cout<<"The value of pi is "<< pi<<".";
    // char c = 's';
    // cout<<"\nThe value of char is "<<c;
    // return 0;
}
