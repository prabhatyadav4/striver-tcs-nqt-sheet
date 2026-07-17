/*
Q63. Convert Decimal to Binary

Topic: Number System

Difficulty: Easy

Pattern: Base Conversion / Powers of Two

Problem Statement:

You are given a non-negative decimal integer N.

Convert the given decimal number into its equivalent binary representation.

Input Format:

The input contains one non-negative integer N.

Output Format:

Print the binary representation of N.

Constraints:

0 <= N <= 10^9

Sample Input:

13

Sample Output:

1101

Explanation:

13 can be represented as:

13 = 8 + 4 + 1
   = 2^3 + 2^2 + 2^0

Therefore:

13 in decimal = 1101 in binary

Approach:

1. Divide the number repeatedly by 2.
2. Store the remainder after every division.
3. Each remainder will be either 0 or 1.
4. The remainders are generated from right to left.
5. Reverse the stored result to obtain the binary representation.

Example:

N = 13

13 / 2 = 6, remainder = 1
6  / 2 = 3, remainder = 0
3  / 2 = 1, remainder = 1
1  / 2 = 0, remainder = 1

Remainders generated: 1011

Reverse them:

1101

Time Complexity: O(log N)

Space Complexity: O(log N)
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

    string binary = "";

    while (n > 0)
    {
        int remainder = n % 2;
        binary += char(remainder + '0');
        n /= 2;
    }

    reverse(binary.begin(), binary.end());

    cout << binary;

    return 0;
}