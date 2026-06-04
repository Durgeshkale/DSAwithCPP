/*
Question:
Find the row with maximum number of 1's in a binary matrix.

Each row is sorted in increasing order, meaning all 0's come first
and then all 1's.

If multiple rows have the same maximum number of 1's,
return the row with the minimum index.

Example:
Input:
mat =
0 0 1
0 1 1
0 0 0

Output:
Row index = 1
Number of 1's = 2

Intuition:
Since every row is sorted, we can use binary search to find
the first occurrence of 1 in every row.

If first 1 is at index x,
then number of 1's in that row = n - x.

Then we compare count of 1's for all rows and store the row
with maximum count.

Approach:
1. For every row, apply lower bound to find first index of 1.
2. Count ones using: n - firstIndexOfOne.
3. If current row has more 1's than previous maximum, update answer.
4. Since we update only when count is greater, the minimum index is preserved automatically.

Time Complexity:
O(m * log n)

Space Complexity:
O(1)
*/

#include <bits/stdc++.h>
using namespace std;

//lowerbound
int lowerBound(vector<int> &row, int n, int x) {

    int low = 0;
    int high = n - 1;

    int ans = n;

    while(low <= high) {

        int mid = low + (high - low) / 2;

        if(row[mid] >= x) {
            ans = mid;
            high = mid - 1;
        }

        else {
            low = mid + 1;
        }
    }

    return ans;
}

vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {

    int m = mat.size();
    int n = mat[0].size();

    int index = -1;
    int max_cnt = 0;

    for(int i = 0; i < m; i++) {

        int cnt_ones = n - lowerBound(mat[i], n, 1);

        if(cnt_ones > max_cnt) {
            max_cnt = cnt_ones;
            index = i;
        }
    }

    return {index, max_cnt};
}

int main() {

    int m, n;

    cout << "Enter number of rows: ";
    cin >> m;

    cout << "Enter number of columns: ";
    cin >> n;

    vector<vector<int>> mat(m, vector<int>(n));

    cout << "Enter matrix elements row-wise: ";
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    vector<int> ans = rowAndMaximumOnes(mat);

    cout << "Row index with maximum 1's: " << ans[0] << endl;
    cout << "Maximum number of 1's: " << ans[1];

    return 0;
}
