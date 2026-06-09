/*
Leetcode 3689. Maximum Total Subarray Value I

Question:
You are given an integer array nums of length n and an integer k.

You need to choose exactly k non-empty subarrays of nums.

- Subarrays may overlap.
- The same subarray can be chosen multiple times.

The value of a subarray is:

max(subarray) - min(subarray)

Return the maximum possible total value.

Example 1:
Input:
nums = [1,3,2]
k = 2

Output:
4

Explanation:
Choose [1,3] => 3 - 1 = 2
Choose [1,3,2] => 3 - 1 = 2

Total = 4

Example 2:
Input:
nums = [4,2,5,1]
k = 3

Output:
12

Explanation:
Maximum possible subarray value = 5 - 1 = 4

Since same subarray can be chosen multiple times,
choose it 3 times.

Answer = 4 + 4 + 4 = 12

Intuition:

At first it looks like we need to find the best k subarrays.

But if we observe carefully,
the same subarray can be chosen multiple times.

So we only need to find the maximum value of a single subarray.

The maximum value possible is:

(global maximum element - global minimum element)

because there always exists a subarray containing both.

Since we can reuse that subarray k times,

answer = k * (global maximum - global minimum)

Approach:

1. Find maximum element in the array.
2. Find minimum element in the array.
3. Calculate their difference.
4. Multiply it by k.
5. Return the answer.

Time Complexity: O(n)

Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

long long maxTotalValue(vector<int>& nums, int k) {

    long long maxi = *max_element(nums.begin(), nums.end());
    long long mini = *min_element(nums.begin(), nums.end());

    // since we can choose same subarray multiple times
    // choose the subarray containing both max and min
    return 1LL * k * (maxi - mini);
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

    int k;

    cout << "Enter value of k: ";
    cin >> k;

    cout << "\nMaximum Total Value: "
         << maxTotalValue(nums, k);

    return 0;
}