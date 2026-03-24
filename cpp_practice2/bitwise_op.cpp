#include<iostream>
using namespace std;
// bitwise operators
int main() {
    int a = 4;
    int b = 6;
    cout<<"a&b: " << (a&b) <<"\n";
    cout<<"a|b: " << (a|b) <<"\n";
    cout<<"~a: " << ~a <<"\n";
    cout<<"a^b: " << (a^b) <<"\n";

    //left and right shift operator
    cout<< (17>>1)<<"\n";
    cout<< (17>>2)<<"\n";
    cout<< (19<<1)<<"\n";
    cout<< (21<<2)<<"\n";

    //pre-post increment decrement 
    int i =7;
    cout<<(++i)<< endl;
    //8
    cout<<(i++)<< endl;
    //8 i=9
    cout<<(i--)<< endl;
    //9 i=8
    cout<<(--i)<< endl;
    //7


}