/*
Leetcode Premium 2387: Median of Row Wise Sorted Matrix

Question:
Given a row-wise sorted matrix, find the median of the matrix.

Each row of the matrix is sorted in increasing order.
The total number of elements is odd.

Example:
Input:
matrix =
1 3 5
2 6 9
3 6 9

Output:
5

Explanation:
All elements in sorted order:
1 2 3 3 5 6 6 9 9

Median = 5

Intuition:
Since every row is sorted, we know binary search can be used.

One simple way is to put all elements into one array, sort it,
and then find the median.
But that uses extra space and is not worth it.

Instead, we apply binary search on the answer.

The median will always lie between:
minimum element of matrix and maximum element of matrix.

So:
low = minimum element
high = maximum element

The required median position is:
req = (n * m) / 2

Now for every mid, we count how many elements are smaller than
or equal to mid.

If count <= req:
it means mid is too small, so move right.

Else:
mid can be median, so move left.

To count elements <= mid:
Since each row is sorted, we use upper bound on every row.

Time Complexity: O(n * log m * log(maxVal - minVal))
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int>& arr, int m, int x) {

    int low = 0;
    int high = m - 1;

    while(low <= high) {

        int mid = low + (high - low) / 2;

        if(arr[mid] <= x) {
            low = mid + 1;
        }

        else {
            high = mid - 1;
        }
    }

    return low;
}

int countSmallerEquals(vector<vector<int>>& matrix, int x, int n, int m) {

    int cnt = 0;

    for(int i = 0; i < n; i++) {

        cnt += upperBound(matrix[i], m, x);
    }

    return cnt;
}

int findMedian(vector<vector<int>>& matrix) {

    int low = INT_MAX;
    int high = INT_MIN;

    int n = matrix.size();
    int m = matrix[0].size();

    for(int i = 0; i < n; i++) {

        low = min(low, matrix[i][0]);

        high = max(high, matrix[i][m - 1]);
    }

    int req = (n * m) / 2;

    while(low <= high) {

        int mid = low + (high - low) / 2;

        int small_equal = countSmallerEquals(matrix, mid, n, m);

        if(small_equal <= req) {
            low = mid + 1;
        }

        else {
            high = mid - 1;
        }
    }

    return low;
}

int main() {

    int n, m;

    cout << "Enter number of rows: ";
    cin >> n;

    cout << "Enter number of columns: ";
    cin >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    cout << "Enter matrix elements row-wise:" << endl;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Median of matrix is: ";
    cout << findMedian(matrix);

    return 0;
}