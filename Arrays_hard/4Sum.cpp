/* leetcode 18 4sum 
is very similar problem to 3 sum 
we have to find all the unique quadruplets in an array who's sum is equal to target given
to solve this we use similar two pointer appraoch and firslty we sort the array so that we get sorted output also it is
easier to figure out which pointer to move when sum is greater or smaller
what we do is we fix i=0 and j = i+1 and move two pointers k and l in array to find the unique quadraplets
and then change positon of i and j along with teh loop*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> solveFourSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        for (int j = i + 1; j < n; j++) {
            if (j != i + 1 && nums[j] == nums[j - 1]) continue;

            int k = j + 1;
            int l = n - 1;

            while (k < l) {
                long long sum = 0;
                sum += nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];

                if (sum == target) {
                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    k++;
                    l--;

                    while (k < l && nums[k] == nums[k - 1]) k++;
                    while (k < l && nums[l] == nums[l + 1]) l--;
                }
                else if (sum > target) {
                    l--;
                }
                else {
                    k++;
                }
            }
        }
    }

    return ans;
}

void printAns(const vector<vector<int>>& ans) {
    if (ans.empty()) {
        cout << "No quadruplets found" << endl;
        return;
    }

    cout << "Quadruplets are:" << endl;
    for (auto quad : ans) {
        cout << "[ ";
        for (int x : quad) {
            cout << x << " ";
        }
        cout << "]" << endl;
    }
}

int main() {
    int n, target;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter target: ";
    cin >> target;

    vector<vector<int>> ans = solveFourSum(nums, target);
    printAns(ans);

    return 0;
}