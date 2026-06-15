/*
Leetcode 167. Two Sum II - Input Array Is Sorted

Question:
Given a 1-indexed array of integers numbers that is sorted in
non-decreasing order, find two numbers such that they add up
to a specific target number.

Return the indices of the two numbers (1-indexed).

You may assume that there is exactly one solution.

Example 1:
Input:
numbers = [2,7,11,15]
target = 9

Output:
[1,2]

Explanation:
numbers[0] + numbers[1] = 2 + 7 = 9

Example 2:
Input:
numbers = [2,3,4]
target = 6

Output:
[1,3]

Example 3:
Input:
numbers = [-1,0]
target = -1

Output:
[1,2]

Intuition:

Since the array is already sorted,
we can use the Two Pointer approach.

If the current sum is too large,
we need a smaller value, so move the right pointer left.

If the current sum is too small,
we need a larger value, so move the left pointer right.

This way we eliminate one side in every step
and find the answer efficiently.

Approach:

1. Place one pointer at the beginning.
2. Place another pointer at the end.
3. Calculate current sum.
4. If sum == target:
      return indices.
5. If sum > target:
      move right pointer left.
6. If sum < target:
      move left pointer right.
7. Continue until answer is found.

Time Complexity: O(n)

Each pointer moves at most n times.

Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {

    int n = numbers.size();

    int low = 0;
    int high = n - 1;

    while(low < high) {

        int sum = numbers[low] + numbers[high];

        // pair found
        if(sum == target) {
            return {low + 1, high + 1};
        }

        // need smaller sum
        else if(sum > target) {
            high--;
        }

        // need larger sum
        else {
            low++;
        }
    }

    return {};
}

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> numbers(n);

    cout << "Enter sorted array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    vector<int> ans = twoSum(numbers, target);

    cout << "Indices: ";
    cout << ans[0] << " " << ans[1];

    return 0;
}