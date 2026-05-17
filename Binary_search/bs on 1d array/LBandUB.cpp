#include <iostream>
#include <vector>
using namespace std;

// LOWER BOUND
// First index or smallest index where arr[i] >= target
int lowerBound(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    int ans = arr.size();

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(arr[mid] >= target) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return ans;
}

// UPPER BOUND
// First index or smallest index where arr[i] > target
int upperBound(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    int ans = arr.size();

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(arr[mid] > target) {
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

    vector<int> arr(n);

    cout << "Enter sorted array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    int lb = lowerBound(arr, target);
    int ub = upperBound(arr, target);

    cout << "Lower Bound Index: " << lb << endl;
    cout << "Upper Bound Index: " << ub << endl;

    return 0;
}