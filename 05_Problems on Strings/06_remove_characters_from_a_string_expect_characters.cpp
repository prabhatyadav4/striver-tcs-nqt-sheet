/*
Q54. Remove Characters From a String Except Alphabets

Topic:  Strings

Difficulty: Easy

Pattern:    Character Filtering / ASCII

TCS Frequency:  High

Constraints:
1 ≤ Length of String ≤ 10^5
String may contain alphabets, digits, spaces and special characters.

Input Format:
One string:    S

Output Format:
Print the string containing only alphabetic characters.

Sample Input:
Hello123 World!

Sample Output:
HelloWorld

Sample Input:
TCS@NQT#2026

Sample Output:
TCSNQT

Sample Input:
P@r#a&b+h*a^t

Sample Output:
Prabhat

TCS Story Version:

A data-cleaning system receives a string containing alphabets,
numbers, spaces and special characters.

Before storing the data, the system needs to keep only alphabetic
characters.

Given a string S, remove every character except alphabets and
print the resulting string.

Programming Concept Used:

Character Classification

An alphabet can be:

Lowercase:
a to z

Uppercase:
A to Z

Key Observation:

For every character, check whether it is an alphabet.

If it is:
    Keep it.

Otherwise:
    Skip it.

For an efficient in-place solution, use the read-and-write
index technique.
*/

#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    string s;
    getline(cin, s);

    for (char ch : s)
    {
        if (isalpha(ch))
        {
            cout << ch;
        }
    }

    return 0;
}