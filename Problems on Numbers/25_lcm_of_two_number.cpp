/*
Q50. Find the LCM of Two Numbers — Brute Force

Topic: Numbers

Difficulty: Easy

Pattern: Multiples / Divisibility

Problem Statement:

You are given two positive integers A and B.

Find their Least Common Multiple (LCM).

The LCM of two numbers is the smallest positive number that is
completely divisible by both numbers.

Input Format:

The input contains two space-separated integers A and B.

Output Format:

Print the LCM of A and B.

Constraints:

1 <= A, B <= 10^9

Sample Input:

12 18

Sample Output:

36

Explanation:

Multiples of 12:

12, 24, 36, 48, ...

Multiples of 18:

18, 36, 54, ...

The smallest common multiple is 36.
*/

/*
Brute Force Approach:

1. Start checking numbers from 1.
2. Continue until A * B.
3. Check whether the current number is divisible by both A and B.
4. The first number divisible by both is their LCM.

Time Complexity:    O(A * B)

Space Complexity:   O(1)
*/

#include <iostream>
using namespace std;

int main()
{
    long long a, b;
    cin >> a >> b;

    long long lcm = 1;

    for (long long i = 1; i <= (a * b); i++)
    {
        if (i % a == 0 && i % b == 0)
        {
            lcm = i;
            break;
        }
    }

    cout << lcm;

    return 0;
}

/*
Better Solution

Approach:

The LCM cannot be smaller than the larger of the two numbers.

Therefore:

1. Start checking from max(A, B).
2. Check whether the current number is divisible by both A and B.
3. Increase the current number by max(A, B).
4. The first common multiple found is the LCM.

Example:

A = 12, B = 18

Start from max(12, 18) = 18.

18 is not divisible by 12.
36 is divisible by both 12 and 18.

Therefore, LCM = 36.

Time Complexity:    O(min(A, B)) in the worst case

Space Complexity:   O(1)
*/

#include <iostream>
using namespace std;

int main()
{
    long long a, b;
    cin >> a >> b;

    long long starting = max(a, b);

    for (int i = starting; i <= (a * b); i += starting)
    {
        if (i % a == 0 && i % b == 0)
        {
            cout << i;
            break;
        }
    }

    return 0;
}

/*
Optimal Solution

Approach:

The relationship between GCD and LCM is:

LCM(A, B) = (A / GCD(A, B)) * B

First, calculate the GCD using the Euclidean algorithm.

Then use the GCD to calculate the LCM.

Example:

A = 12, B = 18

GCD(12, 18) = 6

LCM = (12 / 6) * 18
    = 2 * 18
    = 36

Why do we divide before multiplying?

Instead of writing:

(A * B) / GCD

we write:

(A / GCD) * B

This reduces the possibility of integer overflow.

Time Complexity:    O(log(min(A, B)))

Space Complexity:   O(1)
*/

#include <iostream>
using namespace std;

long long findGCD(long long a, long b)
{
    while (b != 0)
    {
        long long remainder = a % b;
        a = b;
        b = remainder;
    }

    return a;
}

int main()
{
    long long a, b;
    cin >> a >> b;

    long long gcd = findGCD(a, b);

    long long lcm = (a / gcd) * b;

    cout << lcm;

    return 0;
}