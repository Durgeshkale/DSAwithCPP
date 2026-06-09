/*
Leetcode 242. Valid Anagram

Question:
Given two strings s and t, return true if t is an
anagram of s, and false otherwise.

An Anagram is a word formed by rearranging the letters
of another word using all the original letters exactly once.

Example 1:
Input:
s = "anagram"
t = "nagaram"

Output:
true

Explanation:
Both strings contain the same characters with the same frequency.

Example 2:
Input:
s = "rat"
t = "car"

Output:
false

Explanation:
Character frequencies are different.

Intuition:

For two strings to be anagrams:

1. Their lengths must be equal.
2. Every character must appear the same number of times
   in both strings.

We can use a frequency array of size 26.

- Increment frequency for characters of s.
- Decrement frequency for characters of t.

If both strings are anagrams,
all frequencies will become 0 at the end.

Approach:

1. If lengths are different, return false.
2. Create a frequency array of size 26 initialized to 0.
3. Traverse s and increment frequencies.
4. Traverse t and decrement frequencies.
5. Check the frequency array.
6. If any value is not 0, return false.
7. Otherwise return true.

Time Complexity: O(n)

Space Complexity: O(1)

(26-sized frequency array)
*/

#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {

    if(s.size() != t.size()) {
        return false;
    }

    int n = s.size();

    int freq[26] = {0};

    // count frequency of characters in s
    for(int i = 0; i < n; i++) {
        freq[s[i] - 'a']++;
    }

    // remove frequency using t
    for(int i = 0; i < n; i++) {
        freq[t[i] - 'a']--;
    }

    // if any frequency is non-zero
    // strings are not anagrams
    for(int i = 0; i < 26; i++) {
        if(freq[i] != 0) {
            return false;
        }
    }

    return true;
}

int main() {

    string s, t;

    cout << "Enter first string: ";
    cin >> s;

    cout << "Enter second string: ";
    cin >> t;

    if(isAnagram(s, t)) {
        cout << "Valid Anagram";
    }
    else {
        cout << "Not An Anagram";
    }

    return 0;
}