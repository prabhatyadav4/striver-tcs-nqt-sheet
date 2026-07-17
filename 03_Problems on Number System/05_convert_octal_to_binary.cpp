/*
Q65. Convert Octal to Binary — Brute Force Solution

Topic: Number System

Difficulty: Easy

Pattern: Base Conversion

Problem Statement:

You are given an octal number containing digits from 0 to 7.

Convert the given octal number into its equivalent binary representation.

Input Format:

The input contains one octal number.

Output Format:

Print the binary equivalent of the octal number.

Sample Input:

146

Sample Output:

1100110

Explanation:

First convert octal 146 to decimal:

146
= 1 * 8^2 + 4 * 8^1 + 6 * 8^0
= 64 + 32 + 6
= 102

Now convert decimal 102 to binary:

102 in decimal = 1100110 in binary
Approach:

1. Read the octal number as a string.
2. Convert it to decimal using:

   decimal = decimal * 8 + currentDigit

3. Convert the decimal number into binary using repeated division by 2.
4. Reverse the binary digits.

Example:

Octal = 146

Octal to decimal:

Read 1:
0 * 8 + 1 = 1

Read 4:
1 * 8 + 4 = 12

Read 6:
12 * 8 + 6 = 102

Decimal 102 to binary:

102 / 2 = 51, remainder 0
51  / 2 = 25, remainder 1
25  / 2 = 12, remainder 1
12  / 2 = 6,  remainder 0
6   / 2 = 3,  remainder 0
3   / 2 = 1,  remainder 1
1   / 2 = 0,  remainder 1

After reversing:

1100110

Time Complexity: O(D)

Space Complexity: O(D)
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string octal;
    cin >> octal;

    long long decimalNumber = 0;

    for (char digit : octal)
    {
        if (digit < '0' || digit > '7')
        {
            cout << "Invalid Octal Number";
            return 0;
        }

        decimalNumber = decimalNumber * 8 + (digit - '0');
    }

    if (decimalNumber == 0)
    {
        cout << 0;
        return 0;
    }

    string binary = "";

    while (decimalNumber > 0)
    {
        int remainder = decimalNumber % 2;
        binary += char(remainder + '0');
        decimalNumber /= 2;
    }

    reverse(binary.begin(), binary.end());

    cout << binary;

    return 0;
}