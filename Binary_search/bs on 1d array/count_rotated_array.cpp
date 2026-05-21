/*
Find the number of times a sorted array is rotated.

The rotation count is equal to the index of the minimum element.

Example 1:
Input:  [3,4,5,1,2]
Output: 3

Explanation:
The minimum element is 1 and its index is 3,
so the array is rotated 3 times.

Example 2:
Input:  [4,5,6,7,0,1,2]
Output: 4
*/

#include <bits/stdc++.h>
using namespace std;

int countRotations(vector<int>& nums) {

    int n = nums.size();

    int low = 0;
    int high = n - 1;

    int ans = INT_MAX;
    int index = -1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        // if the entire search space is sorted
        if (nums[low] <= nums[high]) {

            if (nums[low] < ans) {
                ans = nums[low];
                index = low;
            }

            break;
        }

        // if left part is sorted
        if (nums[low] <= nums[mid]) {

            if (nums[low] < ans) {
                ans = nums[low];
                index = low;
            }

            low = mid + 1;
        }

        // if right part is sorted
        else {

            if (nums[mid] < ans) {
                ans = nums[mid];
                index = mid;
            }

            high = mid - 1;
        }
    }

    return index;
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

    cout << "Array is rotated ";
    cout << countRotations(nums);
    cout << " times";

    return 0;
}