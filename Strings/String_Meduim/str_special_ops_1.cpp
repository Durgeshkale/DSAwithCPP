/*
Leetcode 3174. Process String With Special Operations I

Question:
You are given a string s consisting of lowercase letters
and special characters '*', '#', and '%'.

Process the string as follows:

1. '*'  -> Remove the last character from the result (if any).
2. '#'  -> Duplicate the current result.
3. '%'  -> Reverse the current result.
4. Letter -> Append it to the result.

Return the final processed string.

Example:
Input:
s = "a#b%*"

Processing:
"a"     -> "a"
"#"     -> "aa"
"b"     -> "aab"
"%"     -> "baa"
"*"     -> "ba"

Output:
"ba"

Intuition:

We build the answer string step by step.

For every character:
- Letter → add it.
- '*' → remove last character.
- '#' → duplicate the current string.
- '%' → reverse the current string.

By simulating the operations in order,
we get the final result.

Approach:

1. Create an empty result string.
2. Traverse every character of s.
3. Apply the corresponding operation.
4. Return the final result string.

Time Complexity: O(n + total operations)

Worst case can be O(n²)
because '#' duplicates the current string.

Space Complexity: O(n)

Result string stores the final answer.
*/

#include <bits/stdc++.h>
using namespace std;

string processStr(string s) {

    string result = "";

    for(char ch : s) {

        // remove last character
        if(ch == '*') {

            if(!result.empty()) {
                result.pop_back();
            }
        }

        // duplicate current string
        else if(ch == '#') {
            result += result;
        }

        // reverse current string
        else if(ch == '%') {
            reverse(result.begin(), result.end());
        }

        // normal character
        else {
            result.push_back(ch);
        }
    }

    return result;
}

int main() {

    string s;

    cout << "Enter string: ";
    cin >> s;

    cout << "Processed String: "
         << processStr(s);

    return 0;
}