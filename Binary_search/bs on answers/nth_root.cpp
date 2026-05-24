/* In this question we have to find out the nth root of the given no.

Example n = 4, m = 81
1 * 1* 1* 1 = 1
2 * 2 * 2 * 2 = 16
3 * 3 * 3 * 3 = 81
so 3 is 4th root of 16

we can use linear search but tc will be  O(m log n)

so we use binary search on answers
 gives Tc = O(log n * log m)*/

#include<bits/stdc++.h>
using namespace std;

//calculation of x power n
int fast_power(int mid , int n){
    int ans  = 1;

    while(n > 0){
        //power is odd
        if(n % 2 == 1){
            ans = ans * mid;
        }

        //square the number
        mid = mid * mid;

        //divide the power by 2
        n = n / 2;
    }
    return ans;
}

int nth_root(int n,  int m){
    int low  = 1;
    int  high = m;

    while(low <= high){
        int mid = low + (high - low)/2;

        if(fast_power(mid , n) == m) return mid;
        
        else if(fast_power(mid , n) < m){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}

int main(){
    int n ;
    cout<<"Enter the value of n : ";
    cin >> n; 
    
    int m;
    cout<<"Enter the number who's nth root you want to find : ";
    cin >> m;

    int ans = nth_root(n , m);

    if(ans == -1){
        cout << m <<" doesn't have " << n <<"th root";
    }
    else{
        cout << n <<"th root of " << m <<" is : " << ans;
    }
    return 0;
}