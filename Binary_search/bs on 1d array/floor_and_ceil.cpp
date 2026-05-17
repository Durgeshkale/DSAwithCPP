#include <iostream>
#include <vector>
using namespace std;

// FLOOR VALUE
// Greatest value <= target
int floorValue(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    int ans = -1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(arr[mid] <= target) {
            ans = arr[mid];
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return ans;
}

// CEIL VALUE
// Smallest value >= target
int ceilValue(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    int ans = -1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(arr[mid] >= target) {
            ans = arr[mid];
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

    int floorAns = floorValue(arr, target);
    int ceilAns = ceilValue(arr, target);

    cout << "Floor Value: " << floorAns << endl;
    cout << "Ceil Value: " << ceilAns << endl;

    return 0;
}