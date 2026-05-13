/* leetcode 493 
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].

we solve it just like we solve inversion pairs

but when we were merging before that we check if arr[i] > arr[right] * 2 true
if it is true  then we move  right ++ and do it until the condition is false and just as it is false
we do cnt += (right -  (mid + 1))

here right i basically mid + 1 i.e the first element of the divided array
*/

#include <bits/stdc++.h>
using namespace std;

// function to count reverse pairs
int countPairs(vector<int> &arr, int low, int mid, int high) {
    int cnt = 0;
    int right = mid + 1;

    for (int i = low; i <= mid; i++) {
        while (right <= high && arr[i] > 2LL * arr[right]) {
            right++;
        }

        cnt += (right - (mid + 1));
    }

    return cnt;
}

// function to merge the halves of the array
void merge(vector<int> &arr, int low, int mid, int high) {
    // Create temporary array
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    // Merge two sorted halves
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // copying remaining elements from left half
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // copying remaining elements from right half
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copying sorted elements to original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

// Recursive merge sort function
int merge_sort(vector<int>& arr, int low, int high) {
    if (low >= high) return 0;

    // Find the middle index
    int mid = (low + high) / 2;

    int cnt = 0;

    // Recursively sort the left half
    cnt += merge_sort(arr, low, mid);

    // Recursively sort the right half
    cnt += merge_sort(arr, mid + 1, high);

    // Count reverse pairs before merging
    cnt += countPairs(arr, low, mid, high);

    // Merge two sorted halves
    merge(arr, low, mid, high);

    return cnt;
}

int reversePairs(vector<int>& nums) {
    int n = nums.size();

    return merge_sort(nums, 0, n - 1);
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

    int ans = reversePairs(nums);

    cout << "Number of reverse pairs: " << ans << endl;

    return 0;
}