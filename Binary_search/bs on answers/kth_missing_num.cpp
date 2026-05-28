/* Leetcode 1539 Kth missing positive number
Question:
Given a sorted array arr of positive integers and an integer k,
return the kth positive integer that is missing from the array.

Example:
arr = [2,3,4,7,11], k = 5
Missing numbers are: 1,5,6,8,9,10...
So the 5th missing number is 9.

Intuition:
The array is sorted, so binary search can be used.

But we cannot apply normal binary search directly because we are not searching
for an existing element.

Also, this is not exactly binary search on answer because we are not given
a direct answer range.

So we observe one important thing:

At any index i:
missing numbers till index i = arr[i] - (i + 1)

Because in a perfect array, the element at index i should have been i + 1.
So the difference tells how many numbers are missing before that element.

Example:
arr = [2,3,4,7,11]

At index 3:
arr[3] = 7
It should have been 4
Missing count = 7 - 4 = 3

Now we binary search to find where the kth missing number lies.

Approach:
If missing < k:
    It means kth missing number is still on the right side.

Else:
    It means kth missing number lies on the left side or before current index.

At the end:
high points to the element before the answer position
low points to the element after the answer position

Formula:
ans = arr[high] + more

where:
more = k - missing till high

missing till high = arr[high] - (high + 1)

So:
ans = arr[high] + k - (arr[high] - high - 1)
ans = k + high + 1

Since low = high + 1,
we can also write:
ans = k + low

Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int findKthPositive(vector<int>& arr, int k) {

    int n = arr.size();

    int low = 0;
    int high = n - 1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        int missing = arr[mid] - (mid + 1);

        if (missing < k) {
            low = mid + 1;
        }

        else {
            high = mid - 1;
        }
    }

    return k + high + 1;
}

int main() {

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter sorted array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cout << "Enter value of k: ";
    cin >> k;

    cout << "Kth missing positive number is: ";
    cout << findKthPositive(arr, k);

    return 0;
}
