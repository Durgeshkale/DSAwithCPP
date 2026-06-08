/*
Leetcode 2161. Partition Array According to Given Pivot

Question:
You are given an integer array nums and an integer pivot.

Rearrange nums such that:
1. All elements less than pivot appear before elements greater than pivot.
2. All elements equal to pivot appear between them.
3. The relative order of elements less than pivot and greater than pivot is maintained.

Return the rearranged array.

Example 1:
Input:
nums = [9,12,5,10,14,3,10]
pivot = 10

Output:
[9,5,3,10,10,12,14]

Explanation:
Elements smaller than 10:
9, 5, 3

Elements equal to 10:
10, 10

Elements greater than 10:
12, 14

Final array:
[9,5,3,10,10,12,14]

Example 2:
Input:
nums = [-3,4,3,2]
pivot = 2

Output:
[-3,2,4,3]

Intuition:
We need to keep all elements:
- smaller than pivot first
- equal to pivot next
- greater than pivot last

Also, relative order must remain same.

So we create three separate arrays:
smaller, equal, greater

Store elements according to their relation with pivot.

Finally merge all three arrays.

Approach:
1. Traverse the array once.
2. Put each element into:
   - smaller
   - equal
   - greater
3. Clear original array.
4. Insert all elements from:
   smaller -> equal -> greater
5. Return the final array.

Time Complexity: O(n)

Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> pivotArray(vector<int>& nums, int pivot) {

    int n = nums.size();

    vector<int> greater;
    vector<int> equal;
    vector<int> smaller;

    for(int i = 0; i < n; i++) {

        if(nums[i] == pivot) {
            equal.push_back(nums[i]);
        }

        else if(nums[i] < pivot) {
            smaller.push_back(nums[i]);
        }

        else {
            greater.push_back(nums[i]);
        }
    }

    nums.clear();

    for(int j = 0; j < smaller.size(); j++) {
        nums.push_back(smaller[j]);
    }

    for(int k = 0; k < equal.size(); k++) {
        nums.push_back(equal[k]);
    }

    for(int l = 0; l < greater.size(); l++) {
        nums.push_back(greater[l]);
    }

    return nums;
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

    int pivot;

    cout << "Enter pivot: ";
    cin >> pivot;

    vector<int> ans = pivotArray(nums, pivot);

    cout << "Partitioned array: ";

    for(int num : ans) {
        cout << num << " ";
    }

    return 0;
}