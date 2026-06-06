/*
Leetcode 1021. Remove Outermost Parentheses

Question:
A valid parentheses string can be divided into primitive valid strings.

For every primitive string, remove its outermost opening and closing bracket.

Return the final string after removing outermost parentheses from every primitive part.

Example 1:
Input:
s = "(()())(())"

Output:
"()()()"

Explanation:
Primitive parts are:
"(()())" + "(())"

After removing outermost brackets:
"()()" + "()"

Final answer:
"()()()"

Intuition:
We need to remove only the outermost brackets of every primitive part.

So we keep a count of open brackets.

If we see '(':
- increase count
- add it to answer only if count > 1
because count == 1 means it is outer opening bracket.

If we see ')':
- decrease count
- add it to answer only if count > 0
because count == 0 means it is outer closing bracket.

Approach:
1. Take a counter cnt to track current depth of parentheses.
2. Traverse the string.
3. For '(':
   - increase cnt
   - if cnt > 1, add '(' to answer.
4. For ')':
   - decrease cnt
   - if cnt > 0, add ')' to answer.
5. Return answer.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

string removeOuterParentheses(string s) {

    int n = s.length();

    string ans = "";

    int cnt = 0;

    for(int i = 0; i < n; i++) {

        if(s[i] == '(') {

            cnt++;

            if(cnt > 1) {
                ans.append("(");
            }
        }

        else {

            cnt--;

            if(cnt > 0) {
                ans.append(")");
            }
        }
    }

    return ans;
}

int main() {

    string s;

    cout << "Enter parentheses string: ";
    cin >> s;

    cout << "String after removing outermost parentheses: ";
    cout << removeOuterParentheses(s);

    return 0;
}