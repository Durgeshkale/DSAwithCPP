/* 152. Maximum Product Subarray
Given an integer array nums, find a subarray that has the largest product, and return the product.
Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

first appraoch is to use the prefix and suffix product
we calculate the prefix and suffix product and take maximum of them 
whenever we there is zero we reset the product to 1

*/

#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {
    int n = nums.size();

    int ans = INT_MIN;

    int pref = 1, suff = 1;

    for (int i = 0; i < n; i++) {

        if (pref == 0) pref = 1;

        if (suff == 0) suff = 1;

        pref *= nums[i];

        suff *= nums[n - i - 1];

        ans = max(ans, max(pref, suff));
    }

    return ans;
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

    int ans = maxProduct(nums);

    cout << "Maximum product subarray is: " << ans << endl;

    return 0;
}