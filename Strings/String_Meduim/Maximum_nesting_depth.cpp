/*
Leetcode 1614. Maximum Nesting Depth of the Parentheses

Question:
Given a valid parentheses string s, return the nesting depth.

The nesting depth is the maximum number of nested parentheses.

Example 1:
Input:
s = "(1+(2*3)+((8)/4))+1"

Output:
3

Explanation:
The deepest nested part is "((8)/4)"
which has depth 3.

Example 2:
Input:
s = "(1)+((2))+(((3)))"

Output:
3

Explanation:
The maximum nesting depth is 3.

Intuition:

Whenever we encounter '(',
we enter one more level of nesting.

Whenever we encounter ')',
we leave one level of nesting.

So we can maintain a counter:

- Increment for '('
- Decrement for ')'

The maximum value reached by the counter
during traversal is the maximum nesting depth.

Approach:

1. Initialize depth counter = 0.
2. Initialize answer = 0.
3. Traverse the string.
4. If current character is '(':
      increment depth.
5. If current character is ')':
      decrement depth.
6. Update answer with maximum depth seen so far.
7. Return answer.

Time Complexity: O(n)

Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int maxDepth(string s) {

    int n = s.size();

    int cnt = 0;
    int ans = 0;

    for(int i = 0; i < n; i++) {

        if(s[i] == '(') {
            cnt++;
        }
        else if(s[i] == ')') {
            cnt--;
        }

        // store maximum depth reached
        ans = max(ans, cnt);
    }

    return ans;
}

int main() {

    string s;

    cout << "Enter expression: ";
    getline(cin, s);

    cout << "Maximum Nesting Depth: ";
    cout << maxDepth(s);

    return 0;
}