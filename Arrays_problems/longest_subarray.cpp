#include <bits/stdc++.h>
using namespace std;
// we have to find longest subarray who length is equal to the given k
int maxSubArray(vector<int>& arr, int k) {
    int n = arr.size();
    int j = 0;
    int sum = 0;
    int len = 0;

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        while(sum > k) {
            sum -= arr[j];
            j++;
        }

        if(sum == k) {
            len = max(len, i - j + 1);
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

    // this solution is optimal in case of non-negative numbers it gives tc of O(N)
}