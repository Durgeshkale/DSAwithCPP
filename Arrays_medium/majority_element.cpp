/*Majority element leetcode 169: In this problem we have to
find the element which appears more than n/2 times where n is 
size of the array
We applied hash map to get a solution under O(N) complexity
but we get the space complextiy of sc: O(N)
but to get sc of O(1) we use moore's  voting algorithm we cancel out counter if we encounter different element */

#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
    int n = nums.size();
    int cnt = 0;
    int el = 0;

    for(int i = 0; i < n; i++) {
        if(cnt == 0) {
            cnt = 1;
            el = nums[i];
        }
        else if(nums[i] == el) {
            cnt++;
        }
        else {
            cnt--;
        }
    }

    int cnt1 = 0;
    for(int i = 0; i < n; i++) {
        if(el == nums[i]) {
            cnt1++;
        }
    }

    if(cnt1 > (n / 2)) {
        return el;
    }

    return -1;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int ans = majorityElement(nums);

    if(ans != -1) {
        cout << "Majority element is: " << ans << endl;
    } else {
        cout << "No majority element found." << endl;
    }

    return 0;
}