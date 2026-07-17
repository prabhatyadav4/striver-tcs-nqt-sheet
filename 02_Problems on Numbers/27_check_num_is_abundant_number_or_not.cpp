/*
Q52. Check Whether the Given Number is an Abundant Number

Topic: Numbers

Difficulty: Easy

Pattern: Divisors / Sum of Proper Divisors

Problem Statement:

You are given a positive integer N.

A number is called an Abundant Number if the sum of its proper divisors
is greater than the number itself.

Proper divisors of a number are all positive divisors of the number
except the number itself.

Check whether the given number is an Abundant Number.

Input Format:

The input contains one positive integer N.

Output Format:

Print "Abundant Number" if the sum of proper divisors of N is greater
than N.

Otherwise, print "Not an Abundant Number".

Constraints:

1 <= N <= 10^9

Sample Input 1:

12

Sample Output 1:

Abundant Number

Explanation:

The proper divisors of 12 are:

1, 2, 3, 4, 6

Their sum is:

1 + 2 + 3 + 4 + 6 = 16

Since 16 > 12, the number 12 is an Abundant Number.

Sample Input 2:

15

Sample Output 2:

Not an Abundant Number

Explanation:

The proper divisors of 15 are:

1, 3, 5

Their sum is:

1 + 3 + 5 = 9

Since 9 is not greater than 15, the number 15 is not an
Abundant Number.

Approach:

1. Initialize the sum of proper divisors as 0.
2. Check every number from 1 to N / 2.
3. If a number divides N completely, add it to the divisor sum.
4. Compare the divisor sum with N.
5. If the sum is greater than N, the number is abundant.

Time Complexity:

O(N)

Space Complexity:

O(1)
*/

#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    long long divisorSum = 0;

    for (long long i = 1; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            divisorSum += i;
        }
    }

    if (divisorSum > n)
    {
        cout << "Abundant Number";
    }
    else
    {
        cout << "Not an Abundant Number";
    }

    return 0;
}