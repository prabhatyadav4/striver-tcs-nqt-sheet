/*
Q49. Find the GCD of Two Numbers

Topic: Numbers

Difficulty: Easy

Pattern: Euclidean Algorithm

TCS Frequency: High

Problem Statement:

You are given two integers A and B.

Find their Greatest Common Divisor (GCD).

The GCD of two numbers is the largest positive integer that divides
both numbers without leaving a remainder.

Input Format:

The input contains two space-separated integers A and B.

Output Format:

Print the GCD of A and B.

Constraints:

1 <= A, B <= 10^9

Sample Input 1:

12 18

Sample Output 1:

6

Explanation:

Factors of 12 are:

1, 2, 3, 4, 6, 12

Factors of 18 are:

1, 2, 3, 6, 9, 18

The greatest common factor is 6.

Sample Input 2:

20 28

Sample Output 2:

4

Explanation:

4 is the largest number that divides both 20 and 28.
*/

/*
Brute Force

Approach:

1. Start checking from 1.
2. Check every number up to min(A, B).
3. If a number divides both A and B, store it as the current GCD.
4. The last common divisor found will be the greatest common divisor.

Time Complexity: O(min(A, B))

Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

int main()
{
    long long a, b;
    cin >> a >> b;

    long long gcd = 1;

    for (long long i = 1; i <= min(a, b); i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            gcd = i;
        }
    }

    cout << gcd;

    return 0;
}

/*
Better Solution

Approach:

1. Start checking from min(A, B).
2. Move backwards toward 1.
3. The first number that divides both A and B is the GCD.
4. Stop immediately after finding it.

This is better than checking from 1 because we may find the answer early.

Time Complexity: O(min(A, B)) in the worst case

Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

int main()
{
    long long a, b;
    cin >> a >> b;

    for (long long i = min(a, b); i > 0; i--)
    {
        if (a % i == 0 && b % i == 0)
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

The Euclidean Algorithm uses the property:

GCD(A, B) = GCD(B, A % B)

We repeatedly replace:

A = B
B = A % B

When B becomes 0, A contains the GCD.

Example:

A = 48, B = 18

48 % 18 = 12
A = 18, B = 12

18 % 12 = 6
A = 12, B = 6

12 % 6 = 0
A = 6, B = 0

Therefore, GCD = 6.

Time Complexity: O(log(min(A, B)))

Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

int main()
{
    long long a, b;
    cin >> a >> b;

    while (b != 0)
    {
        long long remainder = a % b;
        a = b;
        b = remainder;
    }

    cout << a;

    return 0;
}