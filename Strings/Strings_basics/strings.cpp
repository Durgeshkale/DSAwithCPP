#include <bits/stdc++.h>
using namespace std;

/*
String Class in C++

Definition:
A string is a sequence of characters stored using the string class.

Header:
#include <string>

Advantages over Character Arrays:
- Dynamic size
- Easy input/output
- Built-in functions
- No null character management

Example:
string name = "Durgesh";
*/

int main() {

    // Declaration

    string s1;

    // Initialization

    string s2 = "Durgesh";

    string s3("Hello");

    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;


    // Taking Input (single word)

    string name;

    cout << "\nEnter name: ";
    cin >> name;

    cout << "Name = " << name << endl;


    // Taking Input with Spaces

    cin.ignore();

    string fullName;

    cout << "\nEnter full name: ";
    getline(cin, fullName);

    cout << "Full Name = " << fullName << endl;


    // Length / Size

    cout << "\nLength = " << fullName.length() << endl;
    cout << "Size = " << fullName.size() << endl;


    // Access Characters

    cout << "\nFirst Character = " << fullName[0] << endl;

    cout << "Last Character = "
         << fullName[fullName.size() - 1] << endl;

    cout << "Using at() = "
         << fullName.at(0) << endl;


    // Traversing String

    cout << "\nCharacters: ";

    for(int i = 0; i < fullName.size(); i++) {
        cout << fullName[i] << " ";
    }

    cout << endl;


    // Append

    string a = "Hello";
    string b = " World";

    a.append(b);

    cout << "\nAfter append = " << a << endl;


    // Using + Operator

    string first = "Durgesh";
    string last = " Kale";

    string result = first + last;

    cout << "Using + = " << result << endl;


    // Push Back

    string word = "Code";

    word.push_back('X');

    cout << "\nAfter push_back = "
         << word << endl;


    // Pop Back

    word.pop_back();

    cout << "After pop_back = "
         << word << endl;


    // Empty

    cout << "\nIs Empty ? "
         << word.empty() << endl;


    // Clear

    string temp = "Programming";

    temp.clear();

    cout << "After clear size = "
         << temp.size() << endl;


    // Compare

    string x = "abc";
    string y = "abc";

    if(x == y) {
        cout << "\nStrings are equal" << endl;
    }


    // Compare Function

    cout << "compare() result = "
         << x.compare(y) << endl;


    // Substring

    string str = "Programming";

    cout << "\nSubstring = "
         << str.substr(0, 4) << endl;


    // Find

    cout << "Position of gram = "
         << str.find("gram") << endl;


    // Replace

    string text = "I like Java";

    text.replace(7, 4, "C++");

    cout << "\nAfter replace = "
         << text << endl;


    // Erase

    string city = "Nagpur City";

    city.erase(6, 5);

    cout << "After erase = "
         << city << endl;


    // Insert

    string lang = "I C++";

    lang.insert(2, "love ");

    cout << "After insert = "
         << lang << endl;


    // Reverse

    string rev = "coding";

    reverse(rev.begin(), rev.end());

    cout << "\nReversed = "
         << rev << endl;


    // Sort

    string sortStr = "dbca";

    sort(sortStr.begin(), sortStr.end());

    cout << "Sorted = "
         << sortStr << endl;


    // Count Characters

    string sample = "banana";

    int cnt = count(sample.begin(),
                    sample.end(),
                    'a');

    cout << "Count of a = "
         << cnt << endl;


    // Uppercase

    string upper = "hello";

    for(char &ch : upper) {
        ch = toupper(ch);
    }

    cout << "\nUppercase = "
         << upper << endl;


    // Lowercase

    string lower = "HELLO";

    for(char &ch : lower) {
        ch = tolower(ch);
    }

    cout << "Lowercase = "
         << lower << endl;


    // String to Integer

    string num = "123";

    int n = stoi(num);

    cout << "\nString to int = "
         << n + 10 << endl;


    // Integer to String

    int value = 456;

    string converted = to_string(value);

    cout << "Int to string = "
         << converted << endl;


    return 0;
}