/*Leetcode 53 maximum subarray: Given an integer array nums, find the subarray with the largest sum, and return its sum.
brute approach is to try out all the possible subarray but tc is n^3 
so to get the optimal solution we use kadane's algo
as we keep iterating on array we keeps on calculating sum but if we get sum lesser than 0
we skip that no. and replace the start as i i.e current index of the where i is. */
#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    int maxi = INT_MIN;
    int ansStart = -1;
    int ansEnd = -1;
    int start = 0;

    for(int i = 0; i < n; i++) {
        if(sum == 0) {
            start = i;
        }

        sum += nums[i];

        if(sum > maxi) {
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }

        if(sum < 0) {
            sum = 0;
        }
    }

    cout << "Maximum subarray is from index " << ansStart 
         << " to " << ansEnd << endl;

    cout << "Subarray elements are: ";
    for(int i = ansStart; i <= ansEnd; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return maxi;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int ans = maxSubArray(nums);

    cout << "Maximum subarray sum is: " << ans << endl;

    return 0;
}