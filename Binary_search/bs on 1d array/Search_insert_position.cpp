/* Leetcode 35  Search intsert position
in the above question we have to find the index where the target element exist and if it doesn't exist
we have to find the index where we can insert the element
to find that we use the concept of lower bound */

#include <iostream>
#include <vector>
using namespace std;

// Function to find search insert position
int searchInsert(vector<int>& nums, int target) {

    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int ans = n;

    // Using Lower Bound concept
    while(low <= high) {

        int mid = low + (high - low) / 2;

        if(nums[mid] == target) {
            return mid;
        }

        else if(nums[mid] >= target) {
            ans = mid;
            high = mid - 1;
        }

        else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter sorted array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    int index = searchInsert(nums, target);

    cout << "Insert/Search Position: " << index << endl;

    return 0;
}