/*
Leetcode 13. Roman to Integer

Question:
Roman numerals are represented by seven different symbols:

I = 1
V = 5
X = 10
L = 50
C = 100
D = 500
M = 1000

Given a Roman numeral string s, convert it to an integer.

Example 1:
Input:
s = "III"

Output:
3

Explanation:
III = 1 + 1 + 1 = 3

Example 2:
Input:
s = "LVIII"

Output:
58

Explanation:
L = 50, V = 5, III = 3
Total = 58

Example 3:
Input:
s = "MCMXCIV"

Output:
1994

Explanation:
M = 1000
CM = 900
XC = 90
IV = 4

Total = 1994

Intuition:

Normally Roman numerals are added.

Example:
VI = 5 + 1 = 6

But there are special cases where a smaller numeral
appears before a larger numeral.

Example:
IV = 4
IX = 9

In such cases, the smaller value must be subtracted.

So while traversing the string:

- If current value is smaller than the next value,
  subtract it.
- Otherwise add it.

Approach:

1. Store Roman numeral values in a hashmap.
2. Traverse the string.
3. Compare current symbol with next symbol.
4. If current value < next value:
      subtract current value.
5. Else:
      add current value.
6. Return the final answer.

Time Complexity: O(n)

Space Complexity: O(1)

(Only 7 Roman symbols are stored)
*/

#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s) {

    int n = s.size();
    int ans = 0;

    unordered_map<char, int> roman = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    for(int i = 0; i < n; i++) {

        // if current value is smaller than next,
        // subtract it
        if(i < n - 1 && roman[s[i]] < roman[s[i + 1]]) {
            ans -= roman[s[i]];
        }
        else {
            ans += roman[s[i]];
        }
    }

    return ans;
}

int main() {

    string s;

    cout << "Enter Roman Numeral: ";
    cin >> s;

    cout << "Integer Value: ";
    cout << romanToInt(s);

    return 0;
}