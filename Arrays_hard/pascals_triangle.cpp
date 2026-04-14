/*Leetcode 118 pascal's traingle
here we have to print pascal's triangle for we use ncr forumla and simplies it using col's and rows
 */

 #include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ansTriangle;

    for(int i = 0; i < numRows; i++){
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1);

        for(int col = 1; col < i; col++){
            ans = ans * (i - col + 1) / col;
            ansRow.push_back(ans);
        }

        if(i > 0) ansRow.push_back(1);

        ansTriangle.push_back(ansRow);
    }

    return ansTriangle;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> res = generate(n);

    for(auto &row : res){
        for(int x : row){
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}