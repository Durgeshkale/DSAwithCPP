#include <bits/stdc++.h>
using namespace std;

int bs(vector<int>& nums, int low, int high, int target) {
    if (low > high) return -1;

    int mid = low + (high - low) / 2;

    if (nums[mid] == target) return mid;

    else if (nums[mid] < target) {
        return bs(nums, mid + 1, high, target);
    }

    else {
        return bs(nums, low, mid - 1, target);
    }
}

int search(vector<int>& nums, int target) {

    // recursive approach
    return bs(nums, 0, nums.size() - 1, target);

    /*
    // iterative binary search

    int n = nums.size();

    int low = 0;
    int high = n - 1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (nums[mid] == target) return mid;

        else if (nums[mid] < target) {
            low = mid + 1;
        }

        else {
            high = mid - 1;
        }
    }

    return -1;
    */
}

int main() {

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter sorted array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter target element: ";
    cin >> target;

    int ans = search(nums, target);

    if (ans != -1) {
        cout << "Target found at index: " << ans << endl;
    }

    else {
        cout << "Target not found" << endl;
    }

    return 0;
}