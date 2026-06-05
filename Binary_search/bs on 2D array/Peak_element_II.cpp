/*
Leetocde 1901. Find a Peak Element II
Question:
A peak element in a 2D grid is an element that is strictly greater
than its left, right, top, and bottom neighbors.

Given a 2D matrix mat, find any peak element and return its position {row, col}.

You may assume the whole matrix is surrounded by -1.

Example:
Input:
mat =
1  4
3  2

Output:
0 1

Explanation:
mat[0][1] = 4 is greater than left, bottom, and outside boundary.

Intuition:
In 1D peak element, we used binary search by comparing left and right.

Here in 2D, we can apply binary search on columns.

For every middle column:
1. Find the maximum element in that column.
2. Since it is maximum in its column, it is already greater than top and bottom.
3. Now we only need to compare left and right.
4. If current element is greater than left and right, it is peak.
5. If left is greater, move to left side.
6. Else move to right side.

This works because we always move towards a greater neighbor,
and a peak must exist in that direction.

Time Complexity: O(n * log m)
For every binary search step on columns,
we traverse all n rows to find maximum element.
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int maxRowEl(vector<vector<int>>& mat, int n, int m, int col) {

    int maxEl = INT_MIN;
    int row = 0;

    for(int i = 0; i < n; i++) {

        if(maxEl < mat[i][col]) {
            row = i;
            maxEl = mat[i][col];
        }
    }

    return row;
}

vector<int> findPeakGrid(vector<vector<int>>& mat) {

    int n = mat.size();
    int m = mat[0].size();

    int low = 0;
    int high = m - 1;

    while(low <= high) {

        int mid = low + (high - low) / 2;

        //find row having maximum element in mid column
        int row = maxRowEl(mat, n, m, mid);

        int left = mid - 1 >= 0 ? mat[row][mid - 1] : -1;
        int right = mid + 1 < m ? mat[row][mid + 1] : -1;

        //if current element is greater than left and right, it is peak
        if(mat[row][mid] > left && mat[row][mid] > right) {
            return {row, mid};
        }

        //if left is greater, peak lies on left side
        else if(mat[row][mid] < left) {
            high = mid - 1;
        }

        //if right is greater, peak lies on right side
        else {
            low = mid + 1;
        }
    }

    return {-1, -1};
}

int main() {

    int n, m;

    cout << "Enter number of rows: ";
    cin >> n;

    cout << "Enter number of columns: ";
    cin >> m;

    vector<vector<int>> mat(n, vector<int>(m));

    cout << "Enter matrix elements row-wise:" << endl;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    vector<int> ans = findPeakGrid(mat);

    cout << "Peak element position is: ";
    cout << ans[0] << " " << ans[1];

    return 0;
}