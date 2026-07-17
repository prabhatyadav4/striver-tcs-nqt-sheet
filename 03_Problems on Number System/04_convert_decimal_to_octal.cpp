/*
Q64. Convert Decimal to Octal — Brute Force Solution

Topic: Number System

Difficulty: Easy

Pattern: Base Conversion

Problem Statement:

You are given a non-negative decimal integer N.

Convert the given decimal number into its equivalent octal representation.

Octal numbers use digits from 0 to 7.

Input Format:

The input contains one non-negative decimal integer N.

Output Format:

Print the octal representation of N.

Constraints:

0 <= N <= 10^9

Sample Input:

100

Sample Output:

144

Explanation:

100 in decimal is equal to 144 in octal.

Approach:

1. Divide the decimal number repeatedly by 8.
2. Store the remainder after every division.
3. Every remainder will be between 0 and 7.
4. The remainders are generated in reverse order.
5. Reverse the stored string to get the octal representation.

Example:

Decimal number = 100

100 / 8 = 12, remainder = 4
12 / 8  = 1,  remainder = 4
1 / 8   = 0,  remainder = 1

Remainders generated:

4 4 1

Reverse them:

1 4 4

Therefore:

100 in decimal = 144 in octal

Time Complexity: O(log₈ N)

Space Complexity: O(log₈ N)
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    if (n == 0)
    {
        cout << 0;
        return 0;
    }

    string octalNumber = "";

    while (n > 0)
    {
        int remainder = n % 8;
        octalNumber += char(remainder + '0');
        n /= 8;
    }

    reverse(octalNumber.begin(), octalNumber.end());

    cout << octalNumber;

    return 0;
}