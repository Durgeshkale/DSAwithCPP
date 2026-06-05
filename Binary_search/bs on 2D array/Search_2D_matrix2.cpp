/*
Leetcode 240. Search a 2D Matrix II
Question:
Write an efficient algorithm that searches for a value target in an m x n matrix.

Properties:
1. Integers in each row are sorted in ascending order.
2. Integers in each column are sorted in ascending order.

Example:

Input:
matrix =
1   4   7   11  15
2   5   8   12  19
3   6   9   16  22
10 13  14  17  24
18 21  23  26  30

target = 5

Output:
true

Intuition:
If we start from top-left or bottom-right,
both row and column values keep increasing.

So we cannot decide in which direction to move.

But if we start from:
top-right (0, m-1)
or
bottom-left (n-1, 0)

one direction increases and the other decreases.

This allows us to eliminate one entire row or column
at every step.

Approach:
Start from top-right corner.

If current element == target:
return true

If current element < target:
move down
because all elements on left are smaller.

If current element > target:
move left
because all elements below are larger.

In every step we eliminate one row or one column,
so total steps are at most n + m.

Time Complexity: O(n + m)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {

    int n = matrix.size();
    int m = matrix[0].size();

    int row = 0;
    int col = m - 1;

    while(row < n && col >= 0) {

        if(matrix[row][col] == target) {
            return true;
        }

        else if(matrix[row][col] < target) {
            row++;
        }

        else {
            col--;
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

    cout << "Enter matrix elements row-wise: " << endl;

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