/*
Leetcode 567. Permutation in String

Question:
Given two strings s1 and s2, return true if s2 contains a permutation of s1,
or false otherwise.

In other words, return true if one of s1's permutations is a substring of s2.

Example 1:
Input:
s1 = "ab"
s2 = "eidbaooo"

Output:
true

Explanation:
"ba" is a permutation of "ab" and exists in s2.

Example 2:
Input:
s1 = "ab"
s2 = "eidboaoo"

Output:
false

Intuition:
We need to check whether any substring of s2 having length equal to s1
contains exactly the same characters as s1.

A permutation means character frequencies must be the same.

So:
1. Store frequency of characters in s1.
2. Take a window of size s1.length() in s2.
3. Compare frequencies.
4. If frequencies match, permutation exists.
5. Otherwise slide the window and keep checking.

This is a classic Fixed Size Sliding Window problem.

Approach:
1. Create frequency array for s1.
2. Create frequency array for first window of size n in s2.
3. Compare both frequency arrays.
4. Slide the window:
   - Add new character.
   - Remove old character.
5. After every slide compare frequencies.
6. If frequencies match, return true.
7. If no window matches, return false.

Time Complexity:
O(26 * (m - n + 1))

Since frequency comparison takes O(26),
it is effectively O(m).

Space Complexity:
O(26 + 26) = O(1)
*/

#include <bits/stdc++.h>
using namespace std;

bool isFreqSame(vector<int>& arr1, vector<int>& arr2) {

    for(int i = 0; i < 26; i++) {

        if(arr1[i] != arr2[i]) {
            return false;
        }
    }

    return true;
}

bool checkInclusion(string s1, string s2) {

    int n = s1.length();
    int m = s2.length();

    if(n > m) {
        return false;
    }

    vector<int> s1_freq(26, 0);
    vector<int> window_freq(26, 0);

    // frequency of s1 and first window
    for(int i = 0; i < n; i++) {

        s1_freq[s1[i] - 'a']++;
        window_freq[s2[i] - 'a']++;
    }

    if(isFreqSame(s1_freq, window_freq)) {
        return true;
    }

    // sliding window
    for(int i = n; i < m; i++) {

        // add new character
        window_freq[s2[i] - 'a']++;

        // remove old character
        window_freq[s2[i - n] - 'a']--;

        if(isFreqSame(s1_freq, window_freq)) {
            return true;
        }
    }

    return false;
}

int main() {

    string s1, s2;

    cout << "Enter s1: ";
    cin >> s1;

    cout << "Enter s2: ";
    cin >> s2;

    if(checkInclusion(s1, s2)) {
        cout << "Permutation exists";
    }
    else {
        cout << "Permutation does not exist";
    }

    return 0;
}