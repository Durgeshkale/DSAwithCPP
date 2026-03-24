#include<iostream>
using namespace std;

int power(int a , int b){
    int ans = 1;
    for (int i = 1; i <= b; i++){
    ans = ans * a;
    }
    return ans;
}

int EvenOdd(int num){
    if(num&1){
        cout<<"The given number is odd. \n";
    }
    else{
        cout<<"The given number is even. \n";
    }
    return 0;
    
}

int ap(int n){
    return 3*n + 7;
}

int countSetbits(int n){
    int count = 0;
    while( n != 0){
        if(n&1){
            count++;
        }
        n = n>>1;
    }
    return count;
}

int main(){
   /* int a , b;
    cout<<"Enter the value of a adnd b: \n";
    cin>> a >> b;
    cout<<"The solution of " <<a<<" power "<<b<<" is :"<<power(a , b);
    */
   //even odd
   /*int num;
   cout<<" Enter the number: \n";
   cin>>num;
   EvenOdd(num); */

   // printinng a given ap
   /*int n;
   cout<<"Enter the value of n: ";
   cin>>n;
   cout<<ap(n);*/

   int a,b;
   cout<<"Enter the value of a and b: \n";
   cin>>a>>b;
   cout<<"The number of set bits are :"<<countSetbits(a)+countSetbits(b);
   return 0;
}