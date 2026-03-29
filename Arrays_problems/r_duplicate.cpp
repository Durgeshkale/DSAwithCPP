#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int i = 0;

    for (int j = 1; j < nums.size(); j++) {
        if (nums[j] != nums[i]) {
            nums[i + 1] = nums[j];
            i++;
        }
    }

    return i + 1;
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

    int k = removeDuplicates(nums);

    cout << "Number of unique elements: " << k << endl;
    cout << "Array after removing duplicates: ";

    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    cout << endl;

    return 0;
}