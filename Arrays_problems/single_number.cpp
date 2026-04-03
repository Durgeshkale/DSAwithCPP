//Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
//Example 1: Input: nums = [2,2,1]   Output: 1
#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int p = 0;

    for(auto x : nums) {
        p ^= x;
    }

    return p;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << singleNumber(nums);

    return 0;
}
