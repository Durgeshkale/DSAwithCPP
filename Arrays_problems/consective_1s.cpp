//find maximum consecutive one's in an array
#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int cnt = 0;
    int maxi = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1) {
            cnt++;
            maxi = max(maxi, cnt);
        } else {
            cnt = 0;
        }
    }
    return maxi;
}

int main() {
    int n;
    cout<<"Enter the size of the array: ";
    cin >> n;

    cout<<"Enter array elements: ";
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "The maximum consecutive ones are: " << findMaxConsecutiveOnes(nums) << endl;

    return 0;
}