#include <iostream>
using namespace std;
int main()
{
    // for loops
    // print n numbers
    /*int n ;
    cout<<"Enter the value of n:"<<"\n";
    cin>> n;
   cout<< "printinng count from 1 to n:";
   for(int i=0; i<=n; i++){
    cout << i <<"\n";
   } */

   // sum of n numbers
   /*int sum=0;
   int n;
   cout<<" Enter the value of n:\n";
   cin>>n;
   for(int i = 0; i <= n; i++){
    sum += i;
   }
   cout<<" The sum of "<<n<<" is : "<<sum; */

   //fibonacci series 
   /*int fib1 = 0;
   int fib2 = 1;
   int fib = 0;
   int n;
   cout<<" Enter the n to find the fibonacci series upto n:";
   cin>>n;
   cout<<" the fibonacci sereis is:\n";
   cout<<fib1<<" ";
   for(int i=0; i <= n; i++){
    fib = fib1 + fib2;
    fib1 = fib2;
    fib2 = fib;
    cout<<fib<<" ";
   }*/

   // check whether the number is prime or  not
   int n;
   cout<<" Enter teh valueo of n:\n";
   cin>>n;
   bool isPrime = 1;
   for(int i=2; i<n; i++){
    if(n%i == 0){
        isPrime = 0;
        break;
    }
   }
   if(isPrime == 0){
    cout<<n<<" is not a prime number.";
   }
   else{
    cout<<n<<" is a prime number";
   }
}