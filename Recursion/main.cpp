#include<bits/stdc++.h>
using namespace std;

int cnt = 0;

void fun(){
    if(cnt==3) return;
    cout<<cnt<<endl;
    cnt ++;
    fun();
}

int printname(int i,int n){
    if(i>n){
        return 0;
    }
    cout<<"Durgesh"<<endl;
    printname(i+1,n);
}

int printnum(int i,int n){
    if(i>n){
        return 0;
    }
    cout<<i<<endl;
    printnum(i+1,n);
}

void revnum(int n){
    if(n<1){
        return;
    }
    cout<<n<<endl;
    n=n-1;
    revnum(n);
}

void revnum2(int i, int n){
    if(i<1){
        return ;
    }
    cout<<i<<endl;
    revnum2(i-1,n);
}

//print linearly using backtracking
void printback(int i, int n){
    if(i<1){
        return ;
    }
    printback(i-1,n);
    cout<<i<<endl;
}

void revback(int i,int n){
    if(i>n){
        return ;
    }
    revback(i+1,n);
    cout<<i<<endl;
}

void sumofn(int i, int sum ){
    
    if(i<1){
        cout<<sum;
        return;
    } 
    
    sumofn(i-1,sum+i);
}

//funtional recursion
int sumofn2(int n){
    if(n == 0){
        return 0;
    }
    return n + sumofn2(n-1);
}

//factorial of n numbers
int fact(int n){
    if(n == 0) return 1;
    return n * fact(n-1);
}

void reversearr(int i, int arr[], int n){
    if (i>= n/2) return;
    
    swap(arr[i],arr[n-i-1]);
    reversearr(i+1,arr,n);
}

//if a string is palindrome or not 
bool f(int i, string &s){
    if (i >=  s.size()/2) return true;
    if(s[i]!=s[s.size()-i-1]) return false;
    return f(i+1,s);
}


int main(){

//fun();

//print name n times using recursion
//int n;
//cout<<"Enter the value of n:";
//cin>>n;
//printname(1,n);
//printnum(1,n);
//revnum(n);

//revnum2(n,n);
//printback(n,n);
//revback(1,n);
//sumofn(n,0);
//cout<<sumofn2(n);
//cout<<fact(n);
//int arr[n];
//for(int i=0; i<n; i++) cin>>arr[i];

//reversearr(0,arr,n);

/*for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
} */

string s = "madam";
cout<<f(0,s);

}