/*
Leetcode 76. Minimum Window Substring

Question:
Given two strings s and t of lengths m and n respectively,
return the minimum window substring of s such that every
character in t (including duplicates) is included in the window.

If there is no such substring, return an empty string "".

Example 1:
Input:
s = "ADOBECODEBANC"
t = "ABC"

Output:
"BANC"

Explanation:
The minimum window containing A, B and C is "BANC".

Example 2:
Input:
s = "a"
t = "a"

Output:
"a"

Example 3:
Input:
s = "a"
t = "aa"

Output:
""

Intuition:

We need the smallest substring that contains all characters
of t with their required frequencies.

Brute force would generate all substrings and check whether
they contain t, which is very expensive.

Since we need a continuous substring, Sliding Window can be used.

We expand the window using the right pointer until all required
characters are present.

Once a valid window is found, we try to shrink it from the left
to get the minimum possible valid window.

Approach:

1. Store frequency of characters required from string t.
2. Maintain a sliding window using left and right pointers.
3. Expand the window by moving right.
4. Track how many required characters are currently satisfied.
5. When all required characters are satisfied:
   - update minimum window length.
   - shrink the window from the left.
6. Continue until the entire string is processed.
7. Return the minimum window substring.

Time Complexity: O(m + n)

Each character enters and leaves the window at most once.

Space Complexity: O(1)

At most 256 characters are stored in the hash maps.
*/

#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {

    int n = t.size();
    int m = s.size();

    unordered_map<char, int> need;

    // required frequencies
    for(char ch : t) {
        need[ch]++;
    }

    int left = 0;
    int right = 0;

    // number of unique characters required
    int req = need.size();

    int formed = 0;

    unordered_map<char, int> window;

    int minWin = INT_MAX;
    int start = 0;

    while(right < m) {

        char ch = s[right];
        window[ch]++;

        // required frequency achieved
        if(need.count(ch) && window[ch] == need[ch]) {
            formed++;
        }

        // valid window found
        while(formed == req) {

            if(right - left + 1 < minWin) {
                minWin = right - left + 1;
                start = left;
            }

            // shrink window
            window[s[left]]--;

            if(need.count(s[left]) &&
               window[s[left]] < need[s[left]]) {
                formed--;
            }

            left++;
        }

        right++;
    }

    if(minWin == INT_MAX) {
        return "";
    }

    return s.substr(start, minWin);
}

int main() {

    string s, t;

    cout << "Enter string s: ";
    cin >> s;

    cout << "Enter string t: ";
    cin >> t;

    cout << "Minimum Window Substring: "
         << minWindow(s, t);

    return 0;
}