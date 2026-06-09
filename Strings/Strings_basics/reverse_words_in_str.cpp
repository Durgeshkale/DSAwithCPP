/*
Leetcode 151. Reverse Words in a String

Question:
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters.

The returned string should:
1. Contain words in reverse order.
2. Have exactly one space between words.
3. Have no leading or trailing spaces.

Example 1:
Input:
s = "the sky is blue"

Output:
"blue is sky the"

Example 2:
Input:
s = "  hello world  "

Output:
"world hello"

Explanation:
Leading and trailing spaces are removed.

Example 3:
Input:
s = "a good   example"

Output:
"example good a"

Explanation:
Multiple spaces between words are reduced to a single space.

Intuition:

We need to reverse the order of words, not the characters.

Instead of extracting words from left to right and storing them,
we can traverse the string from the end.

Whenever we find a word:
1. Find its ending index.
2. Find its starting index.
3. Add that word to the answer.

This automatically places words in reverse order.

Approach:

1. Start from the last index of the string.
2. Skip all spaces.
3. Mark the end of the current word.
4. Move left until a space is found.
5. Extract the word using substr().
6. Add a space before the word if answer already contains words.
7. Repeat until the entire string is processed.

Time Complexity: O(n)

Space Complexity: O(n)

(The answer string itself stores the reversed sentence.)
*/

#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {

    string ans = "";

    int i = s.length() - 1;

    while(i >= 0) {

        // skip extra spaces
        while(i >= 0 && s[i] == ' ') {
            i--;
        }

        if(i < 0) {
            break;
        }

        int end = i;

        // move to start of current word
        while(i >= 0 && s[i] != ' ') {
            i--;
        }

        int start = i + 1;

        // add space before next word
        if(!ans.empty()) {
            ans += ' ';
        }

        ans += s.substr(start, end - start + 1);
    }

    return ans;
}

int main() {

    string s;

    cout << "Enter string: ";
    getline(cin, s);

    cout << "Reversed String: ";
    cout << reverseWords(s);

    return 0;
}