/*
Q31. Check whether a Number is Perfect Number or Not

Topic:  Numbers

Difficulty: Easy

Pattern:    Divisors Sum

TCS Frequency:  High

Constraints:
1 ≤ N ≤ 10^9
Input is a positive integer

Input Format:
A single integer N.

Output Format:
Print:
"Perfect Number" if the number is perfect
"Not Perfect Number" otherwise

Sample Input:   28
Sample Output:  Perfect Number

TCS Story Version:

A company gives a special award to employees whose employee ID satisfies a unique property.

The ID is called a Perfect ID if the sum of all its proper divisors (excluding the number itself) is equal to the ID.

Given an employee ID, determine whether it is a Perfect ID or not.

Mathematical Concept Used:

A Perfect Number is a number whose sum of proper divisors equals the number itself.

Formula:    Sum of Proper Divisors = Number

Example:    28

Proper Divisors: 1, 2, 4, 7, 14

Sum:    1 + 2 + 4 + 7 + 14 = 28

Therefore, 28 is a Perfect Number.

Key Observation:

A number is Perfect if: Sum of all proper divisors = Number

Examples:
6  = 1 + 2 + 3
28 = 1 + 2 + 4 + 7 + 14
496
8128    are Perfect Numbers.
*/

/*
Brute Force:        TC -> O(N)      SC -> O(1)

Algorithm:
1. Traverse from 1 to N-1.
2. If a number divides N, add it to sum.
3. Compare sum with N.
4. If equal → Perfect Number.
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n < 2)
    {
        cout << "Not Perfect Number";
        return 0;
    }

    int sum = 0;

    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
        }
    }

    if (sum == n)
    {
        cout << "Perfect Number";
    }
    else
    {
        cout << "Not Perfect Number";
    }

    return 0;
}

/*
Optimal:    TC -> O(sqrt(N))        SC -> O(1)

Algorithm:
1. Handle N = 1 separately.
2. Initialize sum = 1 because 1 is a divisor of every number > 1.
3. Traverse from 2 to √N.
4. If i divides N:
    Add i.
    Add N/i if both divisors are different.
5. Compare sum with N.
6. If equal → Perfect Number.
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n < 2)
    {
        cout << "Not Perfect Number";
        return 0;
    }

    int sum = 1;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            sum += i;

            if (i != n / i)
            {
                sum += n / i;
            }
        }
    }

    if (sum == n)
    {
        cout << "Perfect Number";
    }
    else
    {
        cout << "Not Perfect Number";
    }

    return 0;
}