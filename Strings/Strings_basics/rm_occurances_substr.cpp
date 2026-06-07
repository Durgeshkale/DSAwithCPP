/*
Leetcode 1910. Remove All Occurrences of a Substring

Question:
Given two strings s and part,
perform the following operation repeatedly:

- Find the leftmost occurrence of part in s.
- Remove it from s.

Return the final string after removing all occurrences of part.

Example 1:
Input:
s = "daabcbaabcbc"
part = "abc"

Output:
"dab"

Explanation:
daabcbaabcbc
↓
dabaabcbc
↓
dababc
↓
dab

Example 2:
Input:
s = "axxxxyyyyb"
part = "xy"

Output:
"ab"

Intuition:
We need to continuously remove part from the string
until it no longer exists.

The find() function gives the first occurrence of part.

If part exists:
- get its starting index
- erase part.length() characters from there

Keep doing this until part is no longer found.

Approach:
1. Find the first occurrence of part.
2. If found, erase it.
3. Repeat until find() returns string::npos.
4. Return the final string.

Time Complexity:
O(n²) in worst case

Space Complexity:
O(1)
*/

#include <bits/stdc++.h>
using namespace std;

string removeOccurrences(string s, string part) {

    int p = part.length();

    while(s.find(part) != string::npos) {

        int start = s.find(part);

        s.erase(start, p);
    }

    return s;
}

int main() {

    string s;
    string part;

    cout << "Enter string s: ";
    cin >> s;

    cout << "Enter substring part: ";
    cin >> part;

    cout << "String after removing all occurrences: ";
    cout << removeOccurrences(s, part);

    return 0;
}