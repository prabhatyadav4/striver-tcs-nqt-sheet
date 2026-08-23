/*
Q74. Count Number of Vowels, Consonants and Spaces in a String

Topic:  Strings

Difficulty: Easy

Pattern:    String Traversal / Character Classification

TCS Frequency:  High

Constraints:
1 ≤ Length of String ≤ 10^5
String may contain uppercase letters, lowercase letters and spaces.

Input Format:
One string:    S

Output Format:
Print:
Vowels: <count>
Consonants: <count>
Spaces: <count>

Sample Input:
Hello World

Sample Output:
Vowels: 3
Consonants: 7
Spaces: 1

Explanation:

String = "Hello World"

Vowels:
e, o, o
Count = 3

Consonants:
H, l, l, W, r, l, d
Count = 7

Spaces:
1
Count = 1

TCS Story Version:

A text-processing system analyzes a message entered by a user.

Given a string, count the number of vowels, consonants and spaces
present in the string.

Mathematical / Programming Concept Used:

Vowels:
a, e, i, o, u

Consonants:
Alphabetic characters other than vowels.

Space:
The blank character ' '.

Key Observation:

Traverse the string character by character.

For every character:
1. If it is a vowel → increase vowel count.
2. Else if it is an alphabet → increase consonant count.
3. Else if it is a space → increase space count.

Using tolower(), uppercase and lowercase vowels can be
handled using the same condition.
*/

/*
Brute Force:        TC -> O(N)      SC -> O(1)

Algorithm:
1. Read the string.
2. Traverse every character.
3. Convert the character to lowercase.
4. Check whether it is a vowel.
5. Otherwise, check whether it is a consonant.
6. If it is a space, increase the space count.
7. Print all three counts.
*/

#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    string s;
    getline(cin, s);

    int vowels = 0;
    int consonants = 0;
    int spaces = 0;

    for (char ch : s)
    {
        unsigned char c = static_cast<unsigned char>(ch);

        if (isspace(c))
        {
            spaces++;
        }
        else if (isalpha(c))
        {
            c = static_cast<unsigned char>(tolower(c));

            if (c == 'a' || c == 'e' || c == 'i' ||
                c == 'o' || c == 'u')
            {
                vowels++;
            }
            else
            {
                consonants++;
            }
        }
    }

    cout << "Vowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;
    cout << "Spaces: " << spaces;

    return 0;
}

/*
Better:     TC -> O(N)      SC -> O(1)

Algorithm:
1. Read the complete string.
2. Traverse every character.
3. Use a separate function to check whether the character is a vowel.
4. If it is a vowel, increase vowel count.
5. Else if it is an alphabet, increase consonant count.
6. Else if it is a space, increase space count.
7. Print the counts.
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

    int vowels = 0;
    int consonants = 0;
    int spaces = 0;

    for (char ch : s)
    {
        if (isVowel(ch))
        {
            vowels++;
        }
        else if (isalpha(ch))
        {
            consonants++;
        }
        else if (ch == ' ')
        {
            spaces++;
        }
    }

    cout << "Vowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;
    cout << "Spaces: " << spaces;

    return 0;
}

/*
Optimal:        TC -> O(N)      SC -> O(1)

Algorithm:
1. Read the complete string using getline().
2. Initialize:
   vowels = 0
   consonants = 0
   spaces = 0
3. Traverse the string once.
4. If character is a vowel:
   increase vowels.
5. Else if character is an alphabet:
   increase consonants.
6. Else if character is a space:
   increase spaces.
7. Print the counts.
*/

#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    string s;
    getline(cin, s);

    int vowels = 0;
    int consonants = 0;
    int spaces = 0;

    for (char ch : s)
    {
        ch = tolower(ch);

        if (ch == 'a' || ch == 'e' || ch == 'i' ||
            ch == 'o' || ch == 'u')
        {
            vowels++;
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            consonants++;
        }
        else if (ch == ' ')
        {
            spaces++;
        }
    }

    cout << "Vowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;
    cout << "Spaces: " << spaces;

    return 0;
}