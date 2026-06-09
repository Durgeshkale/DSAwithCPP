/*
Leetcode 1903. Largest Odd Number in String

Question:
You are given a string num representing a large integer.

Return the largest-valued odd integer (as a string)
that is a non-empty substring of num.

If no odd integer exists, return an empty string "".

Example 1:
Input:
num = "52"

Output:
"5"

Explanation:
The only non-empty substrings are:
"5", "2", and "52".

Among them, "5" is the largest odd number.

Example 2:
Input:
num = "4206"

Output:
""

Explanation:
There is no odd digit in the string.

Example 3:
Input:
num = "35427"

Output:
"35427"

Explanation:
The whole number is already odd.

Intuition:
For a number to be odd, its last digit must be odd.

So instead of checking all possible substrings,
we can simply find the rightmost odd digit.

Once we find it, everything before that digit
forms the largest possible odd substring.

Approach:
1. Traverse the string from right to left.
2. Find the first odd digit.
3. Its index becomes the ending index of the answer.
4. Return substring from 0 to that index.
5. If no odd digit is found, return an empty string.

Time Complexity: O(n)

Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

string largestOddNumber(string num) {

    int ind = -1;

    for(int i = num.length() - 1; i >= 0; i--) {

        // check if current digit is odd
        if((num[i] - '0') % 2 == 1) {
            ind = i;
            break;
        }
    }

    // no odd digit found
    if(ind == -1) {
        return "";
    }

    return num.substr(0, ind + 1);
}

int main() {

    string num;

    cout << "Enter number string: ";
    cin >> num;

    cout << "Largest odd substring: ";
    cout << largestOddNumber(num);

    return 0;
}