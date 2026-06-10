/*
Leetcode 8. String to Integer (atoi)

Question:
Implement the myAtoi(string s) function.

The algorithm for myAtoi(string s) is:

1. Read and ignore leading whitespace.
2. Check if the next character is '+' or '-'.
3. Read digits until a non-digit character is found.
4. Convert the digits into a 32-bit signed integer.
5. Clamp the result:
      [-2^31, 2^31 - 1]

Return the final integer.

Example 1:
Input:
s = "42"

Output:
42

Example 2:
Input:
s = "   -42"

Output:
-42

Example 3:
Input:
s = "4193 with words"

Output:
4193

Example 4:
Input:
s = "words and 987"

Output:
0

Example 5:
Input:
s = "-91283472332"

Output:
-2147483648

Explanation:
Value is smaller than INT_MIN,
so return INT_MIN.

Intuition:

We need to simulate the behavior of the atoi() function.

First ignore leading spaces.

Then determine whether the number is positive or negative.

After that, keep reading digits and build the number.

Since the number may exceed integer limits,
we check for overflow while constructing it.

This solution uses recursion.

At every recursive call:
1. Process one digit.
2. Update the number.
3. Check overflow.
4. Move to the next character.

Approach:

1. Skip leading whitespaces.
2. Determine sign (+ or -).
3. Call recursive helper function.
4. Helper function:
      - Stop if out of bounds or non-digit found.
      - Build number using:
            num = num * 10 + digit
      - Check overflow.
      - Recurse for next character.
5. Return the final value.

Time Complexity: O(n)

Space Complexity: O(n)

(Recursive call stack)
*/

#include <bits/stdc++.h>
using namespace std;

int helper(const string &s, int i, long long num, int sign) {

    // stop if out of bounds or non-digit found
    if(i >= s.size() || !isdigit(s[i])) {
        return (int)(sign * num);
    }

    // build number
    num = num * 10 + (s[i] - '0');

    // clamp if overflow
    if(sign == 1 && num > INT_MAX) {
        return INT_MAX;
    }

    if(sign == -1 && num > (long long)INT_MAX + 1) {
        return INT_MIN;
    }

    // process next character
    return helper(s, i + 1, num, sign);
}

int myAtoi(string s) {

    int i = 0;

    // skip leading spaces
    while(i < s.size() && s[i] == ' ') {
        i++;
    }

    // handle sign
    int sign = 1;

    if(i < s.size() && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    return helper(s, i, 0, sign);
}

int main() {

    string s;

    cout << "Enter string: ";
    getline(cin, s);

    cout << "Converted Integer: "
         << myAtoi(s);

    return 0;
}