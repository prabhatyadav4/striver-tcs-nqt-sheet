/*
Q66. Convert Octal to Decimal — Brute Force Solution

Topic: Number System

Difficulty: Easy

Pattern: Base Conversion / Positional Values

Problem Statement:

You are given an octal number containing digits from 0 to 7.

Convert the given octal number into its equivalent decimal value.

Input Format:

The input contains one octal number.

Output Format:

Print the decimal equivalent of the octal number.

If the input contains a digit greater than 7, print:

Invalid Octal Number

Constraints:

The octal number contains digits from 0 to 7.

Sample Input:

146

Sample Output:

102

Explanation:

The positional values of octal 146 are:

1 * 8^2 + 4 * 8^1 + 6 * 8^0

= 1 * 64 + 4 * 8 + 6 * 1

= 64 + 32 + 6

= 102

Approach:

1. Read the octal number as a string.
2. Traverse its digits from left to right.
3. For every digit, multiply the current decimal value by 8.
4. Add the current octal digit.

Formula:

decimalNumber = decimalNumber * 8 + currentDigit

Why does this work?

Whenever a new octal digit is added on the right, all previous digits
shift one position to the left.

Shifting one position to the left in octal means multiplying the
existing value by 8.

Example:

Octal = 146

Read 1:

decimalNumber = 0 * 8 + 1
              = 1

Read 4:

decimalNumber = 1 * 8 + 4
              = 12

Read 6:

decimalNumber = 12 * 8 + 6
              = 102

Time Complexity:

O(D)

Space Complexity:

O(D), because the octal number is stored as a string.
*/

#include <iostream>
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
            cout << "Not a Octal Number";
            return 0;
        }

        decimalNumber = decimalNumber * 8 + (digit - '0');
    }

    cout << decimalNumber;

    return 0;
}