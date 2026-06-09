/*
Leetcode 205. Isomorphic Strings

Question:
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be
replaced to get t.

Rules:
1. All occurrences of a character must map to the same character.
2. No two different characters can map to the same character.
3. A character may map to itself.

Example 1:
Input:
s = "egg"
t = "add"

Output:
true

Explanation:
e -> a
g -> d

Example 2:
Input:
s = "foo"
t = "bar"

Output:
false

Explanation:
o maps to both 'a' and 'r', which is not possible.

Example 3:
Input:
s = "paper"
t = "title"

Output:
true

Intuition:

Instead of storing the actual character mapping,
we can store the last seen position of every character.

If two characters are mapped correctly,
their last seen positions should always match.

Example:

s = "egg"
t = "add"

At every index:
e and a appeared first time -> positions match
g and d appeared at same previous position -> positions match

If at any index the positions differ,
mapping is invalid.

Approach:

1. Create two arrays of size 256.
2. Store last seen position of characters from s and t.
3. Traverse both strings together.
4. If previous positions differ, return false.
5. Otherwise update both positions with current index + 1.
6. If no mismatch occurs, return true.

Time Complexity: O(n)

Space Complexity: O(1)

(256-sized arrays are constant space)
*/

#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t) {

    int n = s.length();

    // stores last seen position of chars
    int m1[256] = {0};
    int m2[256] = {0};

    for(int i = 0; i < n; i++) {

        // if previous positions differ,
        // mapping is invalid
        if(m1[s[i]] != m2[t[i]]) {
            return false;
        }

        // store current position
        m1[s[i]] = i + 1;
        m2[t[i]] = i + 1;
    }

    return true;
}

int main() {

    string s, t;

    cout << "Enter first string: ";
    cin >> s;

    cout << "Enter second string: ";
    cin >> t;

    if(isIsomorphic(s, t)) {
        cout << "Strings are Isomorphic";
    }
    else {
        cout << "Strings are Not Isomorphic";
    }

    return 0;
}