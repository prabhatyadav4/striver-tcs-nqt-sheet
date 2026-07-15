/*
Q. Check if a Number is Automorphic

Topic: Numbers

Difficulty: Easy

Pattern: Number Properties

TCS Frequency: High

Problem Statement:

You are given an integer N.

A number is called an Automorphic Number if its square ends with
the same digits as the number itself.

Check whether the given number is an Automorphic Number.

If the number is automorphic, print:

Automorphic Number

Otherwise, print:

Not an Automorphic Number

Input Format:

The input contains one integer N.

Output Format:

Print "Automorphic Number" if the square of N ends with N itself.

Otherwise, print "Not an Automorphic Number".

Constraints:

0 <= N <= 10^9

Sample Input 1:

5

Sample Output 1:

Automorphic Number

Explanation:

Square of 5:

5 × 5 = 25

The square ends with 5. Therefore, 5 is an Automorphic Number.

Sample Input 2:

25

Sample Output 2:

Automorphic Number

Explanation:

Square of 25:

25 × 25 = 625

The square ends with 25. Therefore, 25 is an Automorphic Number.

Sample Input 3:

76

Sample Output 3:

Automorphic Number

Explanation:

Square of 76:

76 × 76 = 5776

The square ends with 76. Therefore, 76 is an Automorphic Number.

Sample Input 4:

7

Sample Output 4:

Not an Automorphic Number

Explanation:

Square of 7:

7 × 7 = 49

The square does not end with 7. Therefore, 7 is not an
Automorphic Number.

Approach:

1. Calculate the square of N.
2. Count the number of digits present in N.
3. Calculate 10 raised to the power of the number of digits.
4. Extract the last digits of the square using the modulo operator.
5. If the extracted value is equal to N, then N is automorphic.

For example:

N = 25

Square = 625

Number of digits in 25 = 2

Divisor = 10² = 100

625 % 100 = 25

Since the result is equal to N, 25 is an Automorphic Number.

Time Complexity:

O(log N), because we count the digits of the number.

Space Complexity:

O(1), because no extra data structure is used.
*/

#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    long long square = n * n;
    long long temp = n;
    long long divisor = 1;

    if (n == 0)
    {
        divisor = 10;
    }
    else
    {
        while (temp > 0)
        {
            divisor *= 10;
            temp /= 10;
        }
    }

    long long lastDigit = square % divisor;

    if (lastDigit == n)
    {
        cout << "Automorphic Number";
    }
    else
    {
        cout << "Not an Automorphic Number";
    }

    return 0;
}