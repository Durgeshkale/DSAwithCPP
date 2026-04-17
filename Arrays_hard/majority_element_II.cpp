/*Leetcode 229 majority element II
it is very similar to majority element 1 only difference is 
if we have to check if an element appears more than n/3 time
then it is majority element
but previously there was only one majority elemetn cause we have to check for n/2
but if we carefully look at n/3 condition 
let us take an example that we have 9 elements
we canat max have two elements  only which are more than n/3 i.e. 3
so we can solve it moore's voting alogrithm  like we did previous problem just by encountering few edge cases */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0;
        int el1 = INT_MIN, el2 = INT_MIN;
        int mini = n / 3 + 1;

        for (int i = 0; i < n; i++) {
            if (cnt1 == 0 && nums[i] != el2) {
                cnt1 = 1;
                el1 = nums[i];
            }
            else if (cnt2 == 0 && nums[i] != el1) {
                cnt2 = 1;
                el2 = nums[i];
            }
            else if (nums[i] == el1) {
                cnt1++;
            }
            else if (nums[i] == el2) {
                cnt2++;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0;
        cnt2 = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == el1) cnt1++;
            else if (nums[i] == el2) cnt2++;
        }

        //here we manually check if the elements actually appears more than n/3 times
        vector<int> ans;
        if (cnt1 >= mini) ans.push_back(el1);
        if (cnt2 >= mini) ans.push_back(el2);

        return ans;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    vector<int> ans = obj.majorityElement(nums);

    cout << "Majority elements (> n/3): ";
    if (ans.empty()) {
        cout << "None";
    } else {
        for (int x : ans) {
            cout << x << " ";
        }
    }

    return 0;
}