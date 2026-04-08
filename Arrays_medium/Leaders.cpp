/*Leaders the the nums in an array who is greater than every element to right of it 
and the last element of the array is always leader
to solve this problem we iterate the array from the end and
check if the arr[i]>maxi if yes then we push it into the leaders array */

#include <bits/stdc++.h>
using namespace std;

vector<int> Leaders(vector<int> nums) {
    int n = nums.size();
    int maxi = INT_MIN;
    vector<int> leader;

    for(int i = n - 1; i >= 0; i--) {
        if(nums[i] > maxi) {
            maxi = nums[i];
            leader.push_back(nums[i]);
        }
    }

    reverse(leader.begin(), leader.end());
    return leader;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the elements in the array: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> ans = Leaders(nums);

    cout << "Leaders are: ";
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}