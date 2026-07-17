/*
Q61. Convert a Binary Number to Decimal

Topic: Number System

Difficulty: Easy

Pattern: Base Conversion / Positional Value

TCS Frequency: High

Problem Statement:

You are given a binary number containing only digits 0 and 1.

Convert the given binary number into its equivalent decimal number.

In a binary number, each digit has a positional value that is a
power of 2.

For example:

Binary number = 1011

Decimal value:

1 * 2^3 + 0 * 2^2 + 1 * 2^1 + 1 * 2^0

= 8 + 0 + 2 + 1

= 11

Input Format:

The input contains one binary number.

Output Format:

Print the decimal equivalent of the given binary number.

Constraints:

The binary number contains only 0 and 1.

The length of the binary number is between 1 and 63.

Sample Input 1:

1011

Sample Output 1:

11

Explanation:

1011 in binary:

1 * 2^3 + 0 * 2^2 + 1 * 2^1 + 1 * 2^0

= 8 + 0 + 2 + 1

= 11

Sample Input 2:

11001

Sample Output 2:

25

Explanation:

11001 in binary:

1 * 2^4 + 1 * 2^3 + 0 * 2^2 + 0 * 2^1 + 1 * 2^0

= 16 + 8 + 0 + 0 + 1

= 25

Approach:

1. Read the binary number as a string.
2. Initialize decimalNumber as 0.
3. Traverse every binary digit from left to right.
4. Multiply the current decimal value by 2.
5. Add the current binary digit.
6. Print the final decimal value.

Formula used during traversal:

decimalNumber = decimalNumber * 2 + currentDigit

Time Complexity:

O(N), where N is the number of binary digits.

Space Complexity:

O(N), because the binary number is stored as a string.
*/

#include <iostream>
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

        int currentDigit = digit - '0';

        decimalNumber = decimalNumber * 2 + currentDigit;
    }

    cout << decimalNumber;

    return 0;
}