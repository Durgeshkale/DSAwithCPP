#include <bits/stdc++.h>
using namespace std;
//two sum:- in this problem sum of any two array elements must be equal to the given target
vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    unordered_map<int, int> mpp;

    for(int i = 0; i < n; i++) {
        int a = nums[i];
        int other = target - a;

        if(mpp.find(other) != mpp.end()) {
            return {mpp[other], i};
        }

        mpp[a] = i;
    }

    return {};
}

int main() {
    int n, target;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter target: ";
    cin >> target;

    vector<int> ans = twoSum(nums, target);

    if(ans.size() == 2) {
        cout << "Indices are: " << ans[0] << " " << ans[1] << endl;
        cout << "Values are: " << nums[ans[0]] << " + " << nums[ans[1]] << " = " << target << endl;
    } else {
        cout << "No valid pair found." << endl;
    }

    return 0;
}