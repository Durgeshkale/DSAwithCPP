/*
Leetcode 443. String Compression

Question:
Given an array of characters chars, compress it using
the following algorithm:

For each group of consecutive repeating characters:

1. If the group's length is 1, write the character.
2. Otherwise write the character followed by the count.

The compressed string must be stored inside the same array.

Return the new length of the compressed array.

Example 1:
Input:
chars = ['a','a','b','b','c','c','c']

Output:
6

Compressed Array:
['a','2','b','2','c','3']

Example 2:
Input:
chars = ['a']

Output:
1

Compressed Array:
['a']

Example 3:
Input:
chars = ['a','b','b','b','b','b','b','b','b','b','b','b','b']

Output:
4

Compressed Array:
['a','b','1','2']

Explanation:
12 is written as two separate characters:
'1' and '2'.

Intuition:

We need to compress consecutive characters.

For every group:
- Count how many times it appears continuously.
- Write the character once.
- If count > 1, write its digits after it.

Instead of creating a new array,
we overwrite the same array using a write pointer.

Approach:

1. Traverse the array.
2. Count frequency of consecutive same characters.
3. Store the character at index idx.
4. If count > 1:
      convert count to string
      store each digit separately.
5. Return idx as the compressed length.

Time Complexity: O(n)

Space Complexity: O(1)

(ignoring the temporary string used for count conversion)
*/

#include <bits/stdc++.h>
using namespace std;

int compress(vector<char>& chars) {

    int n = chars.size();

    int idx = 0;

    for(int i = 0; i < n; i++) {

        char ch = chars[i];
        int cnt = 0;

        // count consecutive occurrences
        while(i < n && chars[i] == ch) {
            cnt++;
            i++;
        }

        // store character
        chars[idx++] = ch;

        // store count if frequency > 1
        if(cnt > 1) {

            string str = to_string(cnt);

            for(char digit : str) {
                chars[idx++] = digit;
            }
        }

        i--;
    }

    return idx;
}

int main() {

    int n;

    cout << "Enter number of characters: ";
    cin >> n;

    vector<char> chars(n);

    cout << "Enter characters:" << endl;

    for(int i = 0; i < n; i++) {
        cin >> chars[i];
    }

    int len = compress(chars);

    cout << "Compressed Length: " << len << endl;

    cout << "Compressed Array: ";

    for(int i = 0; i < len; i++) {
        cout << chars[i] << " ";
    }

    return 0;
}