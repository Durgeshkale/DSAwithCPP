/*
Question:
Given two sorted arrays a[] and b[] and an integer k,
find the kth element from the final sorted array formed after merging both arrays.

Example:
a = [2, 3, 6, 7, 9]
b = [1, 4, 8, 10]
k = 5

Merged array = [1, 2, 3, 4, 6, 7, 8, 9, 10]
5th element = 6

Output:
6

Approach:
This is similar to Median of Two Sorted Arrays.

Here instead of dividing the array into half,
we divide it such that the left half contains exactly k elements.

low = max(k - n2, 0)
Because we must take at least k - n2 elements from first array if second array has fewer elements.

high = min(k, n1)
Because we cannot take more than k elements or more than n1 elements from first array.
Time Complexity: O(log(min(n1, n2))) 
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int kthElement(vector<int> &a, vector<int> &b, int n1, int n2, int k) {

    if (n1 > n2) {
        return kthElement(b, a, n2, n1, k);
    }

    int low = max(k - n2, 0);
    int high = min(k, n1);

    int left = k;

    while (low <= high) {

        int mid1 = low + (high - low) / 2;
        int mid2 = left - mid1;

        int l1 = INT_MIN;
        int l2 = INT_MIN;

        int r1 = INT_MAX;
        int r2 = INT_MAX;

        if (mid1 < n1) r1 = a[mid1];
        if (mid2 < n2) r2 = b[mid2];

        if (mid1 - 1 >= 0) l1 = a[mid1 - 1];
        if (mid2 - 1 >= 0) l2 = b[mid2 - 1];

        if (l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        }

        else if (l1 > r2) {
            high = mid1 - 1;
        }

        else {
            low = mid1 + 1;
        }
    }

    return 0;
}

int main() {

    int n1;
    cout << "Enter size of first array: ";
    cin >> n1;

    vector<int> a(n1);

    cout << "Enter elements of first sorted array: ";
    for (int i = 0; i < n1; i++) {
        cin >> a[i];
    }

    int n2;
    cout << "Enter size of second array: ";
    cin >> n2;

    vector<int> b(n2);

    cout << "Enter elements of second sorted array: ";
    for (int i = 0; i < n2; i++) {
        cin >> b[i];
    }

    int k;
    cout << "Enter value of k: ";
    cin >> k;

    cout << "Kth element is: ";
    cout << kthElement(a, b, n1, n2, k);

    return 0;
}
