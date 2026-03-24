#include<iostream>
using namespace std;

int main(){
   /* int a, b;
    cout<<" Welcome to calculator! \n";
    cout<<"Enter the value of a and b: \n";
    cin>>a>>b;
    char op ;
    cout<<"Enter the operation to perform: \n";
    cin>>op;
    int sol;
    switch (op)
    {
    case '+':
        sol = a + b;
        cout<<sol;
        break;
    case '-':
        sol = a - b;
        cout<<sol;
        break;

    case '*':
        sol = a * b;
        cout<<sol;
        break;

    case '/':
        sol = a / b;
        cout<<sol;
        break;

    case '%':
        sol = a % b;
        cout<<sol;
        break;
    
    default:
    cout<<"Input is incorrect.";
        break;
    } */

    int amount ;
    cout<<"enter the amount: \n";
    cin>>amount;
    int note100 =0 , note20 = 0, note1 = 0;
    int choice = 1;
    switch (choice)
    {
    case 1:
    note100 = amount / 100;
    amount = amount % 100;

    case 2:
    note20 = amount / 20;
    amount = amount % 20;

    case 3:
        note1 = amount / 1;
        amount =amount % 1;
        break;
    
    default:
    cout<<"invalid input";
        break;
    }

    cout<<"The number of 100 Rs. notes are: "<<note100<<endl;
    cout<<"The number of 20 Rs. notes are: "<<note20<<endl;
    cout<<"The number of 1 Rs. notes are: "<<note1<<endl;
}