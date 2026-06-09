/*
Leetcode 14. Longest Common Prefix

Question:
Write a function to find the longest common prefix string
amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:
Input:
strs = ["flower","flow","flight"]

Output:
"fl"

Explanation:
All strings start with "fl".

Example 2:
Input:
strs = ["dog","racecar","car"]

Output:
""

Explanation:
There is no common prefix among all strings.

Intuition:
A brute force approach is to compare every character
of every string with the first string.

But we can optimize it using sorting.

After sorting the strings lexicographically:
- Strings with the most difference will come at the ends.
- If the first and last strings have a common prefix,
  then every string in between will also have that prefix.

So we only need to compare the first and last strings.

Approach:
1. Sort the array of strings.
2. Take the first and last string.
3. Compare characters one by one.
4. Stop when characters differ.
5. The matched characters form the longest common prefix.

Time Complexity:
O(n * m * log n)

where:
n = number of strings
m = average string length

Sorting dominates the complexity.

Space Complexity:
O(1)
(ignoring the answer string)
*/

#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {

    if(strs.empty()) {
        return "";
    }

    // sort strings in lexicographical order
    sort(strs.begin(), strs.end());

    string first = strs[0];
    string last = strs[strs.size() - 1];

    string ans = "";

    int minLen = min(first.size(), last.size());

    for(int i = 0; i < minLen; i++) {

        if(first[i] != last[i]) {
            break;
        }

        ans += first[i];
    }

    return ans;
}

int main() {

    int n;

    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> strs(n);

    cout << "Enter strings:" << endl;

    for(int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    cout << "Longest Common Prefix: ";
    cout << longestCommonPrefix(strs);

    return 0;
}