#include<iostream>
using namespace std;

int factorial(int n){
    int fact = 1;
    for(int i = 1; i <= n; i++){
        fact = fact * i;
    }
    return fact;
}
int nCr(int n , int r){
    int ans;

    ans = factorial(n)/(factorial(r)* factorial(n-r));
    return ans;
}

bool isPrime(int n){
    for(int i=2; i <n; i++){
        if(n%i == 0) {
            return 0;
        }
    }
    return 1;
}

int fibonacci(int n){
    if(n <= 1){
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);


}

int main(){
    //nCr 
    /*int n , r;
    cout<<"Enter the value of n and r: \n";
    cin>>n>>r;
    cout<<"The nCr is: "<<nCr(n,r);
    */

    //prime or not
    /*
    int n;
    cout<<"Enter a number: \n";
    cin>>n;
    if(isPrime(n)){
        cout<<" is a prime number.";
    }
    else{
        cout<<" is not a prime number.";
    }
    */
   int n;
   cout<<"Enter the required term: \n";
   cin>>n;
   cout<<fibonacci(n);
}