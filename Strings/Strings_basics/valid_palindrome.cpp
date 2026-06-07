/*
Leetcode 125. Valid Palindrome

Question:
Given a string s, return true if it is a palindrome after:
1. converting all uppercase letters into lowercase letters
2. removing all non-alphanumeric characters

Example:
Input:
s = "A man, a plan, a canal: Panama"

Output:
true

Explanation:
After removing non-alphanumeric characters and converting to lowercase:
"amanaplanacanalpanama"

This is a palindrome.

Intuition:
We need to check palindrome, but only for letters and digits.

So we use two pointers:
start from left side
end from right side

If any character is not alphanumeric, skip it.

If both characters are valid, compare them after converting to lowercase.

Approach:
1. Make a function to check if character is alphanumeric.
2. Take two pointers start and end.
3. Skip invalid characters from both sides.
4. Compare lowercase characters.
5. If mismatch found, return false.
6. Else keep moving both pointers.
7. Return true at the end.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

bool isAlphaNumeric(char ch) {

    if((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z')) {
        return true;
    }

    return false;
}

bool isPalindrome(string s) {

    int n = s.length();

    int start = 0;
    int end = n - 1;

    while(start < end) {

        if(!isAlphaNumeric(s[start])) {
            start++;
            continue;
        }

        if(!isAlphaNumeric(s[end])) {
            end--;
            continue;
        }

        if(tolower(s[start]) != tolower(s[end])) {
            return false;
        }

        start++;
        end--;
    }

    return true;
}

int main() {

    string s;

    cout << "Enter string: ";
    getline(cin, s);

    if(isPalindrome(s)) {
        cout << "String is palindrome";
    }
    else {
        cout << "String is not palindrome";
    }

    return 0;
}