/*
Leetcode 1283 Find the Smallest Divisor Given a Threshold

Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

The test cases are generated so that there will be an answer.

Example 1:

Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 
Example 2:

Input: nums = [44,22,33,11,1], threshold = 5
Output: 44

Intuition:
If we carefully observe the question the division can be from 1 to max element in the given array
since it is a range of answers
we can use linear search and check if the divisor follows the above condition
but it will cost TC : O(max)

so to reduce it we can use binary search on answers
from 1 to max_element
since we want to find the minimum divisor
we keep checking on left i.e. minimum side if condition is satisfied by the divisor
TC : O(log(max))

now we have to make the function to if the sum after division is <= threshold or not
it will take TC : O(n)

So overall TC : O(n * loh(max))
*/ 

#include <bits/stdc++.h>
using namespace std;

bool isDivisor(vector<int>& arr, int threshold, int divisor) {
    int n = arr.size();
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += (arr[i] + divisor - 1) / divisor;
    }

    return sum <= threshold;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    int n = nums.size();

    int low = 1;
    int high = *max_element(nums.begin(), nums.end());

    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isDivisor(nums, threshold, mid) == true) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int threshold;
    cout << "Enter threshold: ";
    cin >> threshold;

    cout << "Smallest divisor is: " << smallestDivisor(nums, threshold);

    return 0;
}