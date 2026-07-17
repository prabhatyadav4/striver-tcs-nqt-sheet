/*
Q62. Convert Binary to Octal 

Topic: Number System

Difficulty: Easy

Pattern: Base Conversion

Problem Statement:

You are given a binary number containing only digits 0 and 1.

Convert the given binary number into its equivalent octal number.

Input Format:

The input contains one binary number.

Output Format:

Print the octal equivalent of the binary number.

Sample Input:

101101

Sample Output:

55

Explanation:

First convert binary to decimal:

101101
= 1 * 2^5 + 0 * 2^4 + 1 * 2^3
  + 1 * 2^2 + 0 * 2^1 + 1 * 2^0

= 32 + 0 + 8 + 4 + 0 + 1
= 45

Now convert decimal 45 to octal:

45 / 8 = 5, remainder = 5
5 / 8  = 0, remainder = 5

Therefore, the octal representation is 55.

Approach:

1. Read the binary number as a string.
2. Convert it to decimal using:

   decimal = decimal * 2 + currentDigit

3. Convert the decimal number to octal using repeated division by 8.
4. Reverse the octal digits before printing.

This is better than the brute-force solution because it avoids
repeated calls to pow().

Example:

Binary = 101101

Binary to decimal:

Read 1: 0 * 2 + 1 = 1
Read 0: 1 * 2 + 0 = 2
Read 1: 2 * 2 + 1 = 5
Read 1: 5 * 2 + 1 = 11
Read 0: 11 * 2 + 0 = 22
Read 1: 22 * 2 + 1 = 45

Decimal 45 to octal:

45 / 8 = 5, remainder 5
5 / 8 = 0, remainder 5

Octal = 55

Time Complexity:    O(D)

Space Complexity:   O(D)    Where D is the number of binary digits.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string binary;
    cin >> binary;

    long long decimalNumber = 0;

    for (char digit : binary)
    {
        if (digit != '0' && digit != '1')
        {
            cout << "Invalid Binary Number";
            return 0;
        }

        decimalNumber = decimalNumber * 2 + (digit - '0');
    }

    if (decimalNumber == 0)
    {
        cout << 0;
        return 0;
    }

    string octalNumber = "";

    while (decimalNumber > 0)
    {
        int remainder = decimalNumber % 8;
        octalNumber += char(remainder + '0');
        decimalNumber /= 8;
    }

    reverse(octalNumber.begin(), octalNumber.end());

    cout << octalNumber;

    return 0;
}