/*
Leetcode 81

Search in a Rotated sorted array II

There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting 
array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] 
might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.

the question is asked does duplicates affect the TC
yes, it does, if we encounter all duplicated we might end up divide the array n/2 times
which gives us O(n/2) tc in worst case
but still give O(logn) in avg case

Appraoch:
It is alomst same as the I question
we just have an edge case
when ever we encounter nums[low] == nums[mid] == nums[high] we cannot determine which half of the array is sorted
we just shrink the array.
*/

#include <bits/stdc++.h>
using namespace std;

bool search(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0;
    int high = n - 1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (nums[mid] == target) return true;

        // edge case for duplicates
        if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
            low = low + 1;
            high = high - 1;
            continue;
        }

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

    return false;
}

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements of rotated sorted array: ";

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;

    cout << "Enter target element: ";
    cin >> target;

    bool ans = search(nums, target);

    if (ans) {
        cout << "Element exists";
    }

    else {
        cout << "Element does not exist";
    }

    return 0;
}