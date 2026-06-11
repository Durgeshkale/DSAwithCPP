/*
Leetcode 1781. Sum of Beauty of All Substrings

Question:
The beauty of a string is defined as:

(maximum frequency of any character)
-
(minimum frequency of any character)

among all characters that appear at least once.

Given a string s, return the sum of beauty values
of all its substrings.

Example 1:
Input:
s = "aabcb"

Output:
5

Explanation:

Substring    Beauty
"aab"           1
"aabc"          1
"aabcb"         1
"abcb"          1
"bcb"           1

Total = 5

Example 2:
Input:
s = "aabcbaa"

Output:
17

Intuition:

We need beauty of every possible substring.

For every substring:

beauty =
(max frequency character)
-
(min frequency character)

So we generate all substrings.

While extending a substring,
we keep updating character frequencies.

After updating frequency,
we find:

1. Maximum frequency
2. Minimum frequency

and add:

(maxi - mini)

to the final answer.

Approach:

1. Fix starting index i.
2. Create frequency map.
3. Extend substring using j.
4. Update frequency of s[j].
5. Traverse frequency map:
      find maximum frequency.
      find minimum frequency.
6. Add (maxi - mini) to answer.
7. Repeat for all substrings.

Time Complexity: O(n² * 26)

For every substring we check frequencies of characters.

Space Complexity: O(26)

Frequency map stores at most 26 characters.
*/

#include <bits/stdc++.h>
using namespace std;

int beautySum(string s) {

    int n = s.size();

    int sum = 0;

    for(int i = 0; i < n; i++) {

        unordered_map<char, int> freq;

        for(int j = i; j < n; j++) {

            // increase frequency of current character
            freq[s[j]]++;

            int maxi = INT_MIN;
            int mini = INT_MAX;

            // find max and min frequency
            for(auto it : freq) {

                maxi = max(maxi, it.second);
                mini = min(mini, it.second);
            }

            // add beauty of current substring
            sum += (maxi - mini);
        }
    }

    return sum;
}

int main() {

    string s;

    cout << "Enter string: ";
    cin >> s;

    cout << "Sum of Beauty of All Substrings: "
         << beautySum(s);

    return 0;
}