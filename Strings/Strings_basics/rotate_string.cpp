/*
Leetcode 796. Rotate String

Question:
Given two strings s and goal, return true if and only if
s can become goal after some number of shifts.

A shift on s consists of moving the leftmost character
to the rightmost position.

Example:
s = "abcde"

After one shift:
"bcdea"

After two shifts:
"cdeab"

Example 1:
Input:
s = "abcde"
goal = "cdeab"

Output:
true

Example 2:
Input:
s = "abcde"
goal = "abced"

Output:
false

Intuition:

If we rotate a string and keep appending the removed
characters at the end, every possible rotation of s
will appear inside (s + s).

Example:

s = "abcde"

s + s = "abcdeabcde"

Possible rotations:
abcde
bcdea
cdeab
deabc
eabcd

All are present as substrings of "abcdeabcde".

So if goal exists inside (s + s),
then goal is a valid rotation of s.

Approach:

1. If lengths are different, return false.
2. Create doubled string:
      doubledS = s + s
3. Search goal inside doubledS.
4. If found, return true.
5. Otherwise return false.

Time Complexity: O(n)

Space Complexity: O(n)

(for storing s + s)
*/

#include <bits/stdc++.h>
using namespace std;

bool rotateString(string s, string goal) {

    if(s.length() != goal.length()) {
        return false;
    }

    string doubledS = s + s;

    return doubledS.find(goal) != string::npos;
}

int main() {

    string s, goal;

    cout << "Enter string s: ";
    cin >> s;

    cout << "Enter goal string: ";
    cin >> goal;

    if(rotateString(s, goal)) {
        cout << "True";
    }
    else {
        cout << "False";
    }

    return 0;
}