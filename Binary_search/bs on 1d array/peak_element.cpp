/*
Leetcode :
162. Find Peak Element
A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element and return its index.
If the array contains multiple peaks, return the index of any one peak.

We can imagine:
nums[-1] = nums[n] = -infinity

So, the first and last elements can also be peak elements.

Example:
Input: nums = [1,2,3,1]
Output: 2

Explanation:
nums[2] = 3 is greater than nums[1] and nums[3],
so index 2 is the peak index.

Approach:
1. We need O(log n), so we use binary search.
2. The array is not fully sorted, but around a peak, the graph first increases and then decreases.
3. First, handle edge cases:
   - If there is only one element, it is the peak.
   - If the first element is greater than the second, index 0 is peak.
   - If the last element is greater than the second last, index n-1 is peak.
4. Now search from index 1 to n-2.
5. For every mid:
   - If nums[mid] is greater than both neighbors, mid is peak.
   - If nums[mid] > nums[mid - 1], we are on an increasing slope, so peak must exist on right side.
   - If nums[mid] > nums[mid + 1], we are on a decreasing slope, so peak must exist on left side.
   - If nums[mid] is smaller than both neighbors, we are at a valley/saddle, so we can move to any side.
*/


#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int>& nums) {
    int n = nums.size();

    //if array has only 1 element
    if (n == 1) return 0;

    //if first element is peak since we have -infinity
    if (nums[0] > nums[1]) return 0;

    // if last element is peak...
    if (nums[n - 1] > nums[n - 2]) return n - 1;

    int low = 1;
    int high = n - 2;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        //peak element is at mid
        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
            return mid;
        }

        // if it is increasing then the peak can't be at left
        else if (nums[mid] > nums[mid - 1]) {
            low = mid + 1;
        }

        //if it is decreasing then the peak can't be at right
        else if (nums[mid] > nums[mid + 1]) {
            high = mid - 1;
        }

        //if we are at saddle move to any side
        else {
            low = mid + 1;
        }
    }

    return -1;
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

    cout << "Peak element index is: " << findPeakElement(nums);

    return 0;
}