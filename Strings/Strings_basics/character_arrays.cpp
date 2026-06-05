#include <bits/stdc++.h>
using namespace std;

/*
CHARACTER ARRAYS IN C++

Definition:
A character array is an array that stores characters.

Example:
char name[10];

It can store characters like:
'D', 'u', 'r', 'g', 'e', 's', 'h'

1. NORMAL CHARACTER ARRAY

char arr[5] = {'H', 'e', 'l', 'l', 'o'};

This is just a normal character array.
It is NOT a proper string because there is no null character '\0'.

2. C-STYLE STRING / CHARACTER ARRAY STRING

char name[8] = {'D', 'u', 'r', 'g', 'e', 's', 'h', '\0'};

'\0' is called the NULL CHARACTER.
It tells C++ where the string ends.

Without '\0', cout may print garbage values.

3. SHORTCUT INITIALIZATION

char name[] = "Durgesh";

C++ automatically adds '\0' at the end.

So internally:
'D' 'u' 'r' 'g' 'e' 's' 'h' '\0'

Size = 8, not 7.

4. INPUT CHARACTER ARRAY

char name[20];
cin >> name;

Input:
Durgesh

Output:
Durgesh

But cin stops reading at space.

Input:
Durgesh Kale

Only "Durgesh" will be stored.

5. INPUT WITH SPACES

cin.getline(name, 20);

This reads the full line including spaces.

Example:
Durgesh Kale

6. COMMON FUNCTIONS OF CHARACTER ARRAYS

Header file:
#include <cstring>

strlen(str)      -> finds length excluding '\0'
strcpy(a, b)     -> copies b into a
strcat(a, b)     -> joins b at end of a
strcmp(a, b)     -> compares two strings

strcmp returns:
0  -> both strings are equal
<0 -> first string is smaller
>0 -> first string is greater

7. CHARACTER CHECKING FUNCTIONS

Header file:
#include <cctype>

isalpha(ch)  -> checks alphabet
isdigit(ch)  -> checks digit
islower(ch)  -> checks lowercase
isupper(ch)  -> checks uppercase
tolower(ch)  -> converts to lowercase
toupper(ch)  -> converts to uppercase

*/

int main() {

    // 1. Normal character array
    char arr[5] = {'H', 'e', 'l', 'l', 'o'};

    cout << "Normal character array: ";
    for(int i = 0; i < 5; i++) {
        cout << arr[i];
    }
    cout << endl;


    // 2. C-style string with null character
    char name1[8] = {'D', 'u', 'r', 'g', 'e', 's', 'h', '\0'};

    cout << "Character array as string: ";
    cout << name1 << endl;


    // 3. Shortcut initialization
    char name2[] = "Durgesh";

    cout << "Shortcut initialized string: ";
    cout << name2 << endl;

    cout << "Size including null character: ";
    cout << sizeof(name2) << endl;

    cout << "Length excluding null character: ";
    cout << strlen(name2) << endl;


    // 4. Taking input without space
    char firstName[20];

    cout << "\nEnter first name: ";
    cin >> firstName;

    cout << "Your first name is: ";
    cout << firstName << endl;


    // To clear leftover newline before getline
    cin.ignore();


    // 5. Taking input with spaces
    char fullName[50];

    cout << "\nEnter full name: ";
    cin.getline(fullName, 50);

    cout << "Your full name is: ";
    cout << fullName << endl;


    // 6. Accessing characters using index
    cout << "\nFirst character of full name: ";
    cout << fullName[0] << endl;


    // 7. Printing character array using loop
    cout << "Printing full name using loop: ";

    for(int i = 0; fullName[i] != '\0'; i++) {
        cout << fullName[i];
    }
    cout << endl;


    // 8. Copy function
    char copyName[50];

    strcpy(copyName, fullName);

    cout << "\nCopied name: ";
    cout << copyName << endl;


    // 9. Concatenation function
    char greeting[100] = "Hello ";
    strcat(greeting, fullName);

    cout << "After concatenation: ";
    cout << greeting << endl;


    // 10. Comparing two character arrays
    char str1[] = "apple";
    char str2[] = "apple";

    if(strcmp(str1, str2) == 0) {
        cout << "\nBoth strings are equal" << endl;
    }
    else {
        cout << "\nStrings are not equal" << endl;
    }


    // 11. Character checking functions
    char ch = 'A';

    cout << "\nCharacter: " << ch << endl;

    if(isalpha(ch)) {
        cout << "It is an alphabet" << endl;
    }

    if(isupper(ch)) {
        cout << "It is uppercase" << endl;
    }

    cout << "Lowercase version: ";
    cout << char(tolower(ch)) << endl;


    // 12. Reverse character array manually
    char word[] = "coding";

    int start = 0;
    int end = strlen(word) - 1;

    while(start < end) {
        swap(word[start], word[end]);
        start++;
        end--;
    }

    cout << "\nReversed word: ";
    cout << word << endl;


    // 13. Count vowels
    char text[] = "programming";
    int vowelCount = 0;

    for(int i = 0; text[i] != '\0'; i++) {
        char c = tolower(text[i]);

        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vowelCount++;
        }
    }

    cout << "Number of vowels in programming: ";
    cout << vowelCount << endl;


    return 0;
}