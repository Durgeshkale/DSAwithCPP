/* Leetcode 48 Rotate image
we have to rotate the matrix by 90 degree 
we can make ans matrix and put the elements from the matrix into the rotate form into the ans matrix
but this solution need SC O(n^2)
if we have to solve it into in-place we can use mathematical intution 
what  we can do is we can take the tranpose of the matrix and reverse each row one by one and we get the 
required soltuion 
it give TC of O(n^2) and SC of O(1) which is the most optimal solution  */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();

    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    for(int i = 0; i < n; i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    cout << "Enter matrix elements:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }

    rotate(matrix);

    cout << "Rotated Matrix:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}