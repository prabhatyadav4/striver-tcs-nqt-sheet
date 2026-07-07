/*
Q47. Check if a Number is a Strong Number or Not

Topic:  Numbers

Difficulty: Easy

Pattern:    Factorial / Digit Extraction

TCS Frequency:  Medium

Constraints:    1 ≤ N ≤ 10^9

Input Format:
One number:    N

Output Format:
Print:  Strong Number   or  Not a Strong Number

Sample Input:   145

Sample Output:  Strong Number

Sample Input:   123

Sample Output:  Not a Strong Number

Explanation:    145

Digits: 1, 4, 5

Factorials:
1! = 1
4! = 24
5! = 120

Sum = 1 + 24 + 120 = 145

Since the sum of factorials of digits equals the original number, 145 is a Strong Number.

TCS Story Version:

A security company validates employee IDs using a special rule.

An ID is considered valid only if the sum of the factorials of all its digits
is equal to the original ID.

Given an integer N, determine whether it is a Strong Number.

Mathematical Concept Used:

Factorial

n! = n × (n-1) × (n-2) × ... × 1

Examples:

0! = 1
1! = 1
2! = 2
3! = 6
4! = 24
5! = 120

Strong Number

A number whose sum of the factorials of its digits is equal to the number itself.

Examples:

1 = 1!

2 = 2!

145 = 1! + 4! + 5!

Key Observation

A number contains at most 10 digits (for int/long long).

Each digit is between 0 and 9.

Therefore, we only need to compute factorials for digits 0 to 9.

This makes the solution very efficient.
*/

/*
Brute Force:        TC -> O(D × 9)      SC -> O(1)

Algorithm:
1. Read N.
2. Extract each digit.
3. Compute factorial of every digit using a loop.
4. Add all factorials.
5. Compare the sum with the original number.
*/

#include <iostream>
using namespace std;

int factorial(int n)
{
    int fact = 1;

    for (int i = 2; i <= n; i++)
    {
        fact *= i;
    }

    return fact;
}

int main()
{
    int n;
    cin >> n;

    int original = n;
    int sum = 0;

    while (n > 0)
    {
        int digit = n % 10;
        sum += factorial(digit);
        n /= 10;
    }

    if (sum == original)
    {
        cout << "Strong Number";
    }
    else
    {
        cout << "Not Strong Number";
    }

    return 0;
}

/*
Better:     TC -> O(D)      SC -> O(10)

Algorithm:
1. Precompute factorials from 0 to 9.
2. Read N.
3. Extract each digit.
4. Add the precomputed factorial of each digit.
5. Compare the sum with the original number.
*/

#include <iostream>
using namespace std;

int main()
{
    int factorial[10];

    factorial[0] = 1;
    for (int i = 1; i <= 9; i++)
    {
        factorial[i] = factorial[i - 1] * i;
    }

    int n;
    cin >> n;

    int original = n;
    int sum = 0;

    while (n > 0)
    {
        sum += factorial[n % 10];
        n /= 10;
    }

    if (sum == original)
    {
        cout << "Strong Number";
    }
    else
    {
        cout << "Not Strong Number";
    }

    return 0;
}

/*
Optimal:        TC -> O(D)      SC -> O(10)

Algorithm:
1. Store factorials of digits 0 to 9 in an array.
2. Read N.
3. Extract every digit using %10.
4. Add factorial[digit].
5. If the sum equals the original number,
   print Strong Number.
   Otherwise print Not a Strong Number.
*/

#include <iostream>
using namespace std;

int main()
{
    int factorial[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 36200};

    int n;
    cin >> n;

    int original = n;
    int sum = 0;

    while (n > 0)
    {
        int digit = n % 10;
        sum += factorial[digit];
        n /= 10;
    }

    if (sum == original)
    {
        cout << "Strong Number";
    }
    else
    {
        cout << "Not Strong Number";
    }

    return 0;
}