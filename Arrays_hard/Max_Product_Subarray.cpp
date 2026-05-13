/* 152. Maximum Product Subarray
Given an integer array nums, find a subarray that has the largest product, and return the product.
Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

first appraoch is to use the prefix and suffix product
we calculate the prefix and suffix product and take maximum of them 
whenever we there is zero we reset the product to 1

second approach 
we can keep track of maximum and minimum product 
we keep multiplying the current element with the max and min product both and
so when we encounter 0 it resets

and we ever we encounter it is obviouse that the opposite value will be max so we swap them and

return the max product as result

*/

#include <bits/stdc++.h>
using namespace std;

/* Solution 1
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
    */

//Soltion 2

int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int result = nums[0];
        int maxprod = nums[0];
        int minprod = nums[0];

        for(int i = 1;  i < n; i++){
            int curr = nums[i];

            if(curr < 0) swap(maxprod, minprod);

            maxprod = max(curr, maxprod * curr);
            minprod = min(curr, minprod * curr);

            result = max(result, maxprod);
        }
        return result;
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