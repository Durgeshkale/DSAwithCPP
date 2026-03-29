#include<bits/stdc++.h>
using namespace std;


//multiple recursion

int fib(int n){
    if(n<=1) 
    return n;
    return fib(n-1)+fib(n-2);
}

int main(){
    cout<<fib(16);
}