/*Leetcode 34  First and last occurance of an element in the sorted array
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

to sovle this we can do linear search keeping first = -1 and last = -1 and as we find their occurance replace it with the index
but tc = O(n)

so to reduce it to O(logn)
we can use the concept of lower bound and upper bound*/

#include <bits/stdc++.h>
using namespace std;

int lowerbound(vector<int>& nums, int n, int target) {

    int low = 0;
    int high = n - 1;

    int ans = n;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (nums[mid] >= target) {
            ans = mid;
            high = mid - 1;
        }

        else {
            low = mid + 1;
        }
    }

    return ans;
}

int upperbound(vector<int>& nums, int n, int target) {

    int low = 0;
    int high = n - 1;

    int ans = n;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (nums[mid] > target) {
            ans = mid;
            high = mid - 1;
        }

        else {
            low = mid + 1;
        }
    }

    return ans;
}

vector<int> searchRange(vector<int>& nums, int target) {

    int n = nums.size();

    int lb = lowerbound(nums, n, target);

    if ((lb == n) || (nums[lb] != target)) {
        return {-1, -1};
    }

    return {lb, upperbound(nums, n, target) - 1};
}

int main() {

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter sorted array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter target element: ";
    cin >> target;

    vector<int> ans = searchRange(nums, target);

    cout << "First and Last Position: ";

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}