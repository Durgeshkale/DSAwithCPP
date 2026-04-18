/*Leetcode 15 3Sum
we are given with an array and we have to find triples such that their sum = 0
there must be no duplicate triplets in our answer 
so to solve this we use two pointer approach 
we keep a pointer which iterates the array i.e i and then 
another at i+1 and one more which is at n-1
now our first triple elements is i and we check other to if there exist any who gives sum = 0

solving this way gives us Tc = O(N^2)
and Sc = O(1) excluding output answer list*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            if (nums[i] > 0) break;

            if (nums[i] + nums[i + 1] + nums[i + 2] > 0) break;
            if (nums[i] + nums[n - 2] + nums[n - 1] < 0) continue;

            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum < 0) {
                    j++;
                }
                else if (sum > 0) {
                    k--;
                }
                else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }

        return ans;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    vector<vector<int>> ans = obj.threeSum(nums);

    if (ans.empty()) {
        cout << "No triplets found" << endl;
    } else {
        cout << "Triplets are:" << endl;
        for (auto triplet : ans) {
            cout << "[ ";
            for (int x : triplet) {
                cout << x << " ";
            }
            cout << "]" << endl;
        }
    }

    return 0;
}