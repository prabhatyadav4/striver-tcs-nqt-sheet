/*
Q75. Find the ASCII Value of a Character

Topic:  Strings / Characters

Difficulty: Easy

Pattern:    Character Encoding / ASCII

TCS Frequency:  High

Constraints:
Input contains a single character.

Input Format:
One character:    ch

Output Format:
Print the ASCII value of the given character.

Sample Input:
A

Sample Output:
65

Sample Input:
a

Sample Output:
97

Sample Input:
5

Sample Output:
53

TCS Story Version:

A computer system stores characters internally using numerical codes.

Given a character entered by a user, determine the numerical ASCII value
used by the system to represent that character.

Mathematical / Programming Concept Used:

ASCII

ASCII stands for American Standard Code for Information Interchange.

It assigns a numerical value to characters.

Important ASCII values:

'A' = 65
'B' = 66
...
'Z' = 90

'a' = 97
'b' = 98
...
'z' = 122

'0' = 48
'1' = 49
...
'9' = 57

Key Observation

In C++, char is internally stored as an integer character code.

Therefore, we can simply convert the character to int
and print it.
*/

#include <iostream>
using namespace std;

int main()
{
    char ch;
    cin >> ch;

    cout << (int)ch;

    return 0;
}