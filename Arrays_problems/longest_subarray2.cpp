#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& arr, int k) {
    unordered_map<int, int> mp;
    int sum = 0;
    int len = 0;

    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        if(sum == k) {
            len = i + 1;
        }

        if(mp.find(sum - k) != mp.end()) {
            len = max(len, i - mp[sum - k]);
        }

        if(mp.find(sum) == mp.end()) {
            mp[sum] = i;
        }
    }

    return len;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "The length of longest subarray is: " << maxSubArray(arr, k);

    return 0;

    //its has tc of O(N) and extra sc of O(N)
}