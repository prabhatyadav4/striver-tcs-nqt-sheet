/*
Q76. Remove All Vowels From the String

Topic:  Strings

Difficulty: Easy

Pattern:    String Traversal / Character Filtering

TCS Frequency:  High

Constraints:
1 ≤ Length of String ≤ 10^5
String may contain uppercase and lowercase letters.

Input Format:
One string:    S

Output Format:
Print the string after removing all vowels.

Sample Input:
Hello World

Sample Output:
Hll Wrld

Sample Input:
Programming

Sample Output:
Prgrmmng

Sample Input:
AEIOU

Sample Output:
Empty String

TCS Story Version:

A text-processing system needs to clean a message by removing
all vowel characters.

Given a string S, remove every vowel from the string and print
the remaining characters.

Mathematical / Programming Concept Used:

Vowels:
a, e, i, o, u

Uppercase vowels:
A, E, I, O, U

Key Observation

Traverse the string character by character.

If the current character is NOT a vowel,
keep it in the result.

If it is a vowel,
skip it.

Instead of deleting characters one by one,
we can build a new string containing only
the required characters.
*/

#include <iostream>
#include <cctype>
using namespace std;

bool isVowel(char ch)
{
    ch = tolower(ch);

    return ch == 'a' ||
           ch == 'e' ||
           ch == 'i' ||
           ch == 'o' ||
           ch == 'u';
}

int main()
{
    string s;
    getline(cin, s);

    for (int i = 0; i < s.length();)
    {
        if (isVowel(s[i]))
        {
            s.erase(i, 1);
        }
        else
        {
            i++;
        }
    }

    cout << s;

    return 0;
}