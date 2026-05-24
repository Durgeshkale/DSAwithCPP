/* In this problem we are given with a number n 
and we have to find it's sqrt
Example 1:
n = 9 
since 3*3 = 9 
return 3

Example 2:
n = 28
5 * 5 < 28 and
6 * 6 > 28
return 5

we can use linear search fromm 1 to n and find the max no. who's square is <= n
but tc = O(n) approx

 to get O(log n)
 we can use binary search 
 */

#include<bits/stdc++.h>
using namespace std;

int sqrt_of_n(int n){
    int low = 1;
    int high = n;
    int ans = 1;

    while(low <= high){
        long long mid =  low + (high - low)/2;

        long long val = mid * mid;
        if(val <= n){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}


int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;

    int ans = sqrt_of_n(n);

    cout<< "The sqrt of " << n <<" is : " << ans;

}