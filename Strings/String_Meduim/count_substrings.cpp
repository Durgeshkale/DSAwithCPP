/*
Count Substrings With Exactly K Distinct Characters

Question:
Given a string s consisting of lowercase English letters
and an integer k.

Return the number of substrings that contain exactly
k distinct characters.

Example 1:
Input:
s = "abc"
k = 2

Output:
2

Explanation:
Substrings having exactly 2 distinct characters:
"ab"
"bc"

Example 2:
Input:
s = "aba"
k = 2

Output:
3

Explanation:
Substrings:
"ab"
"ba"
"aba"

Intuition:

Finding substrings with exactly K distinct characters
directly is difficult.

Instead we use:

Exactly(K) =
AtMost(K) - AtMost(K - 1)

Because:

AtMost(K)
contains all substrings having:
1 distinct, 2 distinct, ..., K distinct characters.

AtMost(K - 1)
contains all substrings having:
1 distinct, 2 distinct, ..., K-1 distinct characters.

Subtracting them leaves only the substrings
having exactly K distinct characters.

Approach:

1. Create a function atMostKDistinct().
2. Use sliding window.
3. Expand right pointer.
4. Track frequencies and distinct characters.
5. If distinct > k:
      shrink window from left.
6. For every valid window:
      add (right - left + 1)
      because all those substrings are valid.
7. Answer:
      AtMost(K) - AtMost(K - 1)

Time Complexity: O(n)

Each character enters and leaves the window once.

Space Complexity: O(1)

Frequency array size is fixed (26).
*/

#include <bits/stdc++.h>
using namespace std;

// counts substrings having at most k distinct characters
long long atMostKDistinct(string &s, int k) {

    if(k < 0) {
        return 0;
    }

    int left = 0;
    int distinct = 0;

    long long res = 0;

    int freq[26] = {0};

    for(int right = 0; right < s.size(); right++) {

        int idx = s[right] - 'a';

        if(freq[idx] == 0) {
            distinct++;
        }

        freq[idx]++;

        // shrink window if distinct characters exceed k
        while(distinct > k) {

            int leftIdx = s[left] - 'a';

            freq[leftIdx]--;

            if(freq[leftIdx] == 0) {
                distinct--;
            }

            left++;
        }

        // all substrings ending at right are valid
        res += (right - left + 1);
    }

    return res;
}

// counts substrings having exactly k distinct characters
long long countSubstr(string &s, int k) {

    return atMostKDistinct(s, k)
         - atMostKDistinct(s, k - 1);
}

int main() {

    string s;
    int k;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter k: ";
    cin >> k;

    cout << "Number of substrings with exactly "
         << k << " distinct characters = "
         << countSubstr(s, k);

    return 0;
}