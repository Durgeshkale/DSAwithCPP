/*
Leetcode 74. Search a 2D Matrix
Question:

You are given an m x n integer matrix with these properties:
1. Each row is sorted in non-decreasing order.
2. The first integer of each row is greater than the last integer of the previous row.

Given an integer target, return true if target exists in matrix, otherwise return false.

Example:
Input:
matrix =
1  3  5  7
10 11 16 20
23 30 34 60

target = 3

Output:
true

Intuition:
We have to search an element and the matrix is sorted row-wise.

One way is to find the possible row first and then apply binary search on that row.

But because the first element of every row is greater than the last element
of previous row, we can imagine the whole matrix as one sorted 1D array.

So instead of searching row by row, we directly apply binary search
from index 0 to m*n - 1.

Approach:
1. Treat the matrix like a flattened sorted array.
2. Total elements = n * m.
3. Apply binary search from low = 0 to high = n*m - 1.
4. Convert mid index into matrix coordinates:
   row = mid / m
   col = mid % m
5. Compare matrix[row][col] with target and move low/high normally.

Time Complexity: O(log(n * m))
Space Complexity: O(1)

*/

#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {

    int n = matrix.size();
    int m = matrix[0].size();

    int low = 0;
    int high = n * m - 1;

    while(low <= high) {

        int mid = low + (high - low) / 2;

        int row = mid / m;
        int col = mid % m;

        if(matrix[row][col] == target) {
            return true;
        }

        else if(matrix[row][col] < target) {
            low = mid + 1;
        }

        else {
            high = mid - 1;
        }
    }

    return false;
}

int main() {

    int n, m;

    cout << "Enter number of rows: ";
    cin >> n;

    cout << "Enter number of columns: ";
    cin >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    cout << "Enter matrix elements row-wise: ";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int target;

    cout << "Enter target element: ";
    cin >> target;

    if(searchMatrix(matrix, target)) {
        cout << "Element exists";
    }
    else {
        cout << "Element does not exist";
    }

    return 0;
}