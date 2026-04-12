/* leetcode 54 spiral matrix
in this problem we have to print the elements in the matrix in a spiral order
to solve this problem what we do is 
Traverse matrix in spiral (layer by layer): top row → right col → bottom row → left col
Shrink boundaries after each traversal to avoid revisiting elements */

#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int left = 0, right = m - 1;
    int top = 0, bottom = n - 1;
    vector<int> ans;

    while (top <= bottom && left <= right) {

        for (int i = left; i <= right; i++) ans.push_back(matrix[top][i]);
        top++;

        for (int i = top; i <= bottom; i++) ans.push_back(matrix[i][right]);
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--) ans.push_back(matrix[bottom][i]);
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) ans.push_back(matrix[i][left]);
            left++;
        }
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<int> result = spiralOrder(matrix);

    for (int x : result) cout << x << " ";
    return 0;
}