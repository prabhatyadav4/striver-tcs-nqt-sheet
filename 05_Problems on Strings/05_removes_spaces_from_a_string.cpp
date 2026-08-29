/*
Q77. Remove Spaces From a String

Topic:  Strings

Difficulty: Easy

Pattern:    String Traversal / Character Filtering

TCS Frequency:  High

Constraints:
1 ≤ Length of String ≤ 10^5
The string may contain uppercase letters, lowercase letters,
digits, special characters and spaces.

Input Format:
One string:    S

Output Format:
Print the string after removing all spaces.

Sample Input:
Hello World

Sample Output:
HelloWorld

Sample Input:
TCS NQT Coding

Sample Output:
TCSNQTCoding

Sample Input:
Hello   World

Sample Output:
HelloWorld

TCS Story Version:

A company receives customer information containing unnecessary
spaces. Before storing the information, the system needs to
remove all spaces from the given string.

Given a string S, remove every space character and print the
resulting string.

Programming Concept Used:

Character Filtering

We examine every character of the string.

If the character is a space:
    Skip it.

Otherwise:
    Keep it.

Key Observation

We do not need to remove spaces one by one.

We can either:
1. Create a new string containing only non-space characters.
2. Modify the original string using a write index.

For an efficient in-place solution, use the read-and-write
pointer technique.
*/

#include <iostream>
using namespace std;

int main()
{
    string s;
    getline(cin, s);

    string result;

    for (char ch : s)
    {
        if (ch != ' ')
        {
            result += ch;
        }
    }

    cout << result;

    return 0;
}