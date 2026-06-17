/*
Leetcode 3614. Process String with Special Operations II

Question:
You are given a string s consisting of lowercase English letters
and the special characters '*', '#', and '%'.

Process the string from left to right:

1. Letter  -> append to result.
2. '*'     -> remove last character from result if it exists.
3. '#'     -> duplicate the current result.
4. '%'     -> reverse the current result.

Return the kth character of the final string.
If k is out of bounds, return '.'.

Example:

Input:
s = "a#b%*"
k = 1

Processing:
"a"
"aa"
"aab"
"baa"
"ba"

Output:
'a'

Intuition:

The brute force approach would be to actually build the string.

But '#' can double the string size repeatedly, making the final
string extremely large (up to 10^15 length).

Since we only need the kth character, building the entire string
is unnecessary.

Instead:

1. Calculate only the final length.
2. Start from index k in the final string.
3. Traverse operations in reverse.
4. Undo every operation and keep mapping k back to its original position.
5. Eventually reach the actual character that created position k.

Approach:

Step 1:
Traverse the string and calculate final length.

Letter -> len++
'*'    -> len--
'#'    -> len *= 2
'%'    -> length unchanged

Step 2:
If k >= len, answer does not exist.

Step 3:
Traverse operations from right to left.

Letter:
- If k == len - 1, this character created that position.
- Return it.
- Otherwise len--.

'#':
Before duplication:
abc

After duplication:
abcabc

Original length was len / 2.

Map index back:
k %= originalLength

'%':
Reverse operation.

Before:
abcde

After:
edcba

Undo reverse:
k = len - 1 - k

'*':
Undo deletion.

Length increases by 1.

Step 4:
Continue until the required character is found.

Time Complexity: O(n)

One forward traversal +
One backward traversal.

Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

char processStr(string s, long long k) {

    long long len = 0;

    // calculate final length
    for(char ch : s) {

        if(islower(ch)) {
            len++;
        }

        else if(ch == '*') {

            if(len > 0) {
                len--;
            }
        }

        else if(ch == '#') {
            len *= 2;
        }

        // '%' does not affect length
    }

    if(k >= len) {
        return '.';
    }

    // work backwards
    for(int i = (int)s.size() - 1; i >= 0; i--) {

        char ch = s[i];

        if(islower(ch)) {

            // this character created index len - 1
            if(k == len - 1) {
                return ch;
            }

            len--;
        }

        else if(ch == '#') {

            len /= 2;

            // map k into first copy
            k %= len;
        }

        else if(ch == '%') {

            // undo reverse
            k = len - 1 - k;
        }

        else if(ch == '*') {

            // undo deletion
            len++;
        }
    }

    return '.';
}

int main() {

    string s;
    long long k;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter k: ";
    cin >> k;

    cout << "Answer: " << processStr(s, k);

    return 0;
}