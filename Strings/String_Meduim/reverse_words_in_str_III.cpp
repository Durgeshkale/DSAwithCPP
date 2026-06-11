/*
Leetcode 557. Reverse Words in a String III

Question:
Given a string s, reverse the characters of each word
while preserving whitespace and the original word order.

Example 1:
Input:
s = "Let's take LeetCode contest"

Output:
"s'teL ekat edoCteeL tsetnoc"

Example 2:
Input:
s = "Mr Ding"

Output:
"rM gniD"

Intuition:

We need to reverse every word individually.

Whenever we find the start of a word,
we move forward until we reach a space
or the end of the string.

Now we know the complete range of the word.

We reverse that range and move to the next word.

Approach:

1. Traverse the string using pointer i.
2. Skip spaces.
3. Find the ending index of the current word.
4. Reverse the current word in-place.
5. Move i to the start of the next word.
6. Return the modified string.

Time Complexity: O(n)

Each character is processed a constant number of times.

Space Complexity: O(1)

All reversals are done in-place.
*/

#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {

    int n = s.size();

    int i = 0;

    while(i < n) {

        int idx = i;

        // skip spaces
        if(s[i] == ' ') {
            i++;
            continue;
        }

        // find end of current word
        while(idx < n && s[idx] != ' ') {
            idx++;
        }

        // reverse current word
        reverse(s.begin() + i, s.begin() + idx);

        // move to next word
        i = idx + 1;
    }

    return s;
}

int main() {

    string s;

    cout << "Enter string: ";
    getline(cin, s);

    cout << "Output: " << reverseWords(s);

    return 0;
}