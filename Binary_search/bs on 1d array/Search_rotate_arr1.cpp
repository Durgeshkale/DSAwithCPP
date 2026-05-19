/*
 Leetcode 33 
Search in Rotated Sorted Array
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.
Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

we could've used linear search but it is specifically asked solution for logn
so since the array is sorted and we have to search for an element
we can use binary search

approach:
we have to find the mid
check if mid element is the target if yes return 
else
u check whichh half of the array is sorted
once if you find the sorted half
you check if the target exist in sorted half is yes u eliminate the other half
if not then u eliminate the sorted half and do 
and repeat the above steps in the unsorted part
*/

#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {

    int n = nums.size();

    int low = 0;
    int high = n - 1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (nums[mid] == target) return mid;

        //left part of the array is sorted
        if (nums[low] <= nums[mid]) {

            if (nums[low] <= target && target <= nums[mid]) {
                high = mid - 1;
            }

            else {
                low = mid + 1;
            }
        }

        //right part of the array is sorted
        else {

            if (nums[mid] <= target && target <= nums[high]) {
                low = mid + 1;
            }

            else {
                high = mid - 1;
            }
        }
    }

    return -1;
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

    int target;

    cout << "Enter target element: ";
    cin >> target;

    int ans = search(nums, target);

    if (ans != -1) {
        cout << "Target found at index: " << ans << endl;
    }

    else {
        cout << "Target not found" << endl;
    }

    return 0;
}