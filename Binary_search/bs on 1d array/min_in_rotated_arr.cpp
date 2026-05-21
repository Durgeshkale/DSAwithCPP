/*Leetcode 153
Find the minimum in rotated sorted array

Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.

Example 1:

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.

This is what they expect

to get a log n time solution we can implement binary search
just like previous questions

approach:
since the array is rotated
1. find the sorted part
2. take min from the sorted part as ans
3. now contiune the above to step in remaining array
4. until low > high

one optimization 
if the entire search space is sorted the ans would be min(arr[low],ans)
*/

#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int>& nums) {
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int ans = INT_MAX;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        //if the entire search space is sorted
        if (nums[low] <= nums[high]) {
            ans = min(ans, nums[low]);
            break;
        }

        //if left part is sorted
        if (nums[low] <= nums[mid]) {
            ans = min(ans, nums[low]); // pick the smallest element from the sorted part
            low = mid + 1; // remove the sorted part
        }

        // if the right part is sorted
        else {
            ans = min(ans, nums[mid]);
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter rotated sorted array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Minimum element is: " << findMin(nums);

    return 0;
}