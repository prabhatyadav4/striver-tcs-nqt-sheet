/*
Q44. Power of a Number

Topic:  Numbers

Difficulty: Easy

Pattern:    Exponentiation / Binary Exponentiation

TCS Frequency:  High

Constraints:
-10⁹ ≤ Base ≤ 10⁹
-2³¹ ≤ Exponent ≤ 2³¹−1
Use long long to safely handle negative exponents.

Input Format:
Two numbers:    x n
x → Base
n → Exponent4

Output Format:
Print:  xⁿ

Sample Input:
2 10

Sample Output:
1024

TCS Story Version:

A company encrypts employee IDs by repeatedly multiplying a base value.

Given a base value x and an exponent n, determine the encrypted value xⁿ.

Mathematical Concept Used:

Power Property

x⁰ = 1

x⁻ⁿ = 1 / xⁿ

xⁿ = x × x × x × ... (n times)

Binary Exponentiation

If n is even    xⁿ = (x²)ⁿᐟ²

If n is odd     xⁿ = x × (x²)(ⁿ⁻¹)ᐟ²

Key Observation
Instead of multiplying x exactly n times, we can repeatedly square the base.

This reduces complexity from    O(N)    to  O(log N)
*/

/*
Brute Force:        TC -> O(N)      SC -> O(1)

Algorithm:
1. Read x and n.
2. If exponent is negative
    Convert x into 1/x
    Make exponent positive.
3. Multiply x exactly n times.
4. Print answer.
*/

#include <iostream>
using namespace std;

int main()
{
    double x;
    int n;
    cin >> x >> n;

    long long N = n;

    if (n < 0)
    {
        x = 1 / x;
        N = -N;
    }

    long long ans = 1;

    for (long long i = 0; i < N; i++)
    {
        ans *= x;
    }

    cout << ans;

    return 0;
}

/*
Better:     TC -> O(log N)      SC -> O(log N)

Algorithm:
1. If exponent becomes zero, return 1.
2. If exponent is negative
    Convert x into 1/x
    Make exponent positive.
3. If exponent is even
    Square x
    Divide exponent by 2
4. Otherwise
    Multiply one x
    Solve remaining recursively.
*/

#include <iostream>
using namespace std;

double power(double x, long long n)
{
    if (n == 0)
    {
        return 1;
    }

    if (n < 0)
    {
        return power(1 / x, -n);
    }

    if (n % 2 == 0)
    {
        return power(x * x, n / 2);
    }

    return x * power(x * x, (n - 1) / 2);
}

int main()
{
    double x;
    long long n;
    cin >> x >> n;

    cout << power(x, n);

    return 0;
}

/*
Optimal:        TC -> O(log N)      SC -> O(1)

Algorithm
1. Read x and n.
2. If exponent is negative
    Replace x with 1/x
    Make exponent positive.
3. Initialize answer = 1.
4. While exponent > 0
    If exponent is odd
    Multiply answer by x.
    Square x.
    Divide exponent by 2.
5. Print answer.
*/

#include <iostream>
using namespace std;

int main()
{
    double x;
    long long n;

    cin >> x >> n;

    long long N = n;

    if (N < 0)
    {
        x = 1 / x;
        N = -N;
    }

    double ans = 1;

    while (N > 0)
    {
        if (N & 1)
        {
            ans *= x;
        }

        x *= x;
        N >>= 1;
    }

    cout << ans;

    return 0;
}