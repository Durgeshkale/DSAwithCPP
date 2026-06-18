/*
Leetcode 80. Remove Duplicates from Sorted Array II

Question:
Given an integer array nums sorted in non-decreasing order,
remove some duplicates in-place such that each unique element
appears at most twice.

The relative order of the elements should remain the same.

Return k after placing the final result in the first k positions
of the array.

Example 1:
Input:
nums = [1,1,1,2,2,3]

Output:
5

Modified Array:
[1,1,2,2,3]

Example 2:
Input:
nums = [0,0,1,1,1,1,2,3,3]

Output:
7

Modified Array:
[0,0,1,1,2,3,3]

Intuition:

Since the array is already sorted, duplicates appear together.

We are allowed to keep at most two occurrences of every number.

Instead of counting frequencies separately, we can use a pointer
to build the valid array in-place.

For every new element, check whether it is equal to the element
two positions before the current insertion index.

If they are different, we can safely keep the current element.

If they are the same, adding it would create more than two
occurrences, so we skip it.

Approach:

1. If array size is less than or equal to 2,
   return its size directly.
2. Start insertion pointer i = 2.
3. Traverse the array from index 2 onward.
4. Compare nums[j] with nums[i - 2].
5. If they are different:
   - place nums[j] at index i.
   - increment i.
6. Return i as the new length.

Time Complexity: O(n)

Single traversal of the array.

Space Complexity: O(1)

In-place modification, no extra space used.
*/

#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {

    int n = nums.size();

    if(n <= 2) {
        return n;
    }

    int i = 2;

    for(int j = 2; j < n; j++) {

        // keep element only if it won't become
        // the third occurrence
        if(nums[j] != nums[i - 2]) {
            nums[i] = nums[j];
            i++;
        }
    }

    return i;
}

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter sorted array elements: ";

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k = removeDuplicates(nums);

    cout << "New Length: " << k << endl;

    cout << "Modified Array: ";

    for(int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}