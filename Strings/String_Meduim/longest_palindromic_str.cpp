/*
Leetcode 5. Longest Palindromic Substring

Question:
Given a string s, return the longest palindromic substring in s.

A palindrome is a string that reads the same forward and backward.

Example 1:
Input:
s = "babad"

Output:
"bab"

Explanation:
"aba" is also a valid answer.

Example 2:
Input:
s = "cbbd"

Output:
"bb"

Intuition:

A palindrome mirrors around its center.

For every character in the string, we can consider it as:

1. Center of an odd length palindrome
      Example:
      "racecar"
          c

2. Center between two characters for an even length palindrome
      Example:
      "abba"

For every index, expand towards left and right as long as
characters are equal.

The longest palindrome found during the process is the answer.

Approach:

1. Iterate through every index of the string.
2. Treat current index as center of odd palindrome.
3. Treat current index and next index as center of even palindrome.
4. Expand from center while characters match.
5. Get the maximum palindrome length.
6. If current palindrome is longer than previous best:
      update start index and max length.
7. Return substring(start, maxLen).

Time Complexity: approx O(n²)

For every index we may expand up to O(n).

Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

// function to find palindrome length by expanding from center
int expandFromCenter(string &s, int left, int right) {

    while(left >= 0 &&
          right < s.size() &&
          s[left] == s[right]) {

        left--;
        right++;
    }

    // returns length of palindrome
    return right - left - 1;
}

string longestPalindrome(string s) {

    int n = s.size();

    int start = 0;
    int maxLen = 1;

    for(int i = 0; i < n; i++) {

        // odd length palindrome
        int len1 = expandFromCenter(s, i, i);

        // even length palindrome
        int len2 = expandFromCenter(s, i, i + 1);

        int currLen = max(len1, len2);

        // update answer if longer palindrome found
        if(currLen > maxLen) {

            maxLen = currLen;

            // calculate starting index of the palindromic string
            start = i - (currLen - 1) / 2;
        }
    }

    return s.substr(start, maxLen);
}

int main() {

    string s;

    cout << "Enter string: ";
    cin >> s;

    cout << "Longest Palindromic Substring: "
         << longestPalindrome(s);

    return 0;
}