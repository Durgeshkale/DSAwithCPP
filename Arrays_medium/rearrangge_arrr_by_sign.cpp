/* leetcode 2149 Reaarange the array elements by sign
You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

You should return the array of nums such that the array follows the given conditions:

Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

our apporach we take postive index as 0 and negative index as 1 now we iterate over the array
check if the no. is positive or negative 
if its positive we place it in the answer array at positive index and increment the positive index by two and vice versa
we get tc O(n) and sc O(n)*/


#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
    int n = nums.size();
    int posIndex = 0;
    int negIndex = 1;
    vector<int> ans(n, 0);

    for(int i = 0; i < n; i++) {
        if(nums[i] < 0) {
            ans[negIndex] = nums[i];
            negIndex += 2;
        }
        else {
            ans[posIndex] = nums[i];
            posIndex += 2;
        }
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter size of array (even): ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> result = rearrangeArray(nums);

    cout << "Rearranged array: ";
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}