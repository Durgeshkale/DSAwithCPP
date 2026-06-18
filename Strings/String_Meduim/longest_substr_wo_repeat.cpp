/*
Leetcode 3. Longest Substring Without Repeating Characters

Question:
Given a string s, find the length of the longest substring
without repeating characters.

Example 1:
Input:
s = "abcabcbb"

Output:
3

Explanation:
The answer is "abc", with length 3.

Example 2:
Input:
s = "bbbbb"

Output:
1

Explanation:
The answer is "b", with length 1.

Example 3:
Input:
s = "pwwkew"

Output:
3

Explanation:
The answer is "wke", with length 3.

Intuition:

We need the longest substring having all unique characters.

If we use two loops and check every substring, it will take O(n²).

Since we need a continuous substring, Sliding Window is a natural choice.

We expand the window using the right pointer.

Whenever a duplicate character appears, we shrink the window
from the left until the duplicate is removed.

This way the window always contains unique characters.

Approach:

1. Use two pointers left and right to maintain a window.
2. Store frequency of characters inside the current window.
3. Expand the window by moving right.
4. If a character frequency becomes greater than 1,
   shrink the window from the left until all characters
   become unique again.
5. Update the maximum window length at every step.
6. Return the maximum length found.

Time Complexity: O(n)

Each character is added and removed from the window at most once.

Space Complexity: O(256) ≈ O(1)

Frequency array stores at most 256 ASCII characters.
*/

#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {

    int n = s.size();

    vector<int> freq(256, 0);

    int left = 0;
    int right = 0;

    int ans = 0;

    while(right < n) {

        freq[s[right]]++;

        // shrink window until duplicate is removed
        while(freq[s[right]] > 1) {
            freq[s[left]]--;
            left++;
        }

        ans = max(ans, right - left + 1);

        right++;
    }

    return ans;
}

int main() {

    string s;

    cout << "Enter string: ";
    cin >> s;

    cout << "Length of longest substring without repeating characters: "
         << lengthOfLongestSubstring(s);

    return 0;
}