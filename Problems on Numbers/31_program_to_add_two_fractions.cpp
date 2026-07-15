/*
Q56. Add Two Fractions

Topic: Numbers

Difficulty: Easy

Pattern: Fractions / GCD

Problem Statement:

You are given two fractions:

numerator1 / denominator1

and

numerator2 / denominator2

Add the two fractions and print the result in its simplest form.

The sum of two fractions is calculated as:

numerator =
numerator1 * denominator2 + numerator2 * denominator1

denominator =
denominator1 * denominator2

After calculating the result, divide both the numerator and denominator
by their GCD to convert the fraction into its simplest form.

Input Format:

The input contains four space-separated integers:

numerator1 denominator1 numerator2 denominator2

Output Format:

Print the resulting fraction in the following format:

numerator/denominator

Constraints:

-10^9 <= numerator1, numerator2 <= 10^9

1 <= denominator1, denominator2 <= 10^9

Sample Input 1:

1 2 3 4

Sample Output 1:

5/4

Explanation:

1/2 + 3/4

Taking the common denominator:

1/2 = 2/4

Therefore:

2/4 + 3/4 = 5/4

Sample Input 2:

1 6 1 3

Sample Output 2:

1/2

Explanation:

1/6 + 1/3

Numerator:

1 * 3 + 1 * 6 = 9

Denominator:

6 * 3 = 18

Result:

9/18

GCD of 9 and 18 is 9.

Simplified result:

1/2

Approach:

1. Read the numerator and denominator of both fractions.
2. Cross-multiply and add the numerators.
3. Multiply the denominators.
4. Find the GCD of the resulting numerator and denominator.
5. Divide both values by their GCD.
6. Print the simplified fraction.

Time Complexity:    O(log(min(numerator, denominator)))

Space Complexity:   O(1)
*/

#include <iostream>
using namespace std;

long long findGCD(long long a, long long b)
{
    a = llabs(a);
    b = llabs(b);

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
    long long numerator1, denominator1;
    if (!(cin >> numerator1 >> denominator1))
        return 0;
    long long numerator2, denominator2;
    if (!(cin >> numerator2 >> denominator2))
        return 0;

    long long numerator = (numerator1 * denominator2) + (numerator2 * denominator1);
    long long denominator = (denominator1 * denominator2);

    long long gcd = findGCD(numerator, denominator);
    if (gcd != 0)
    {
        numerator /= gcd;
        denominator /= gcd;
    }

    // ensure denominator is positive
    if (denominator < 0)
    {
        numerator = -numerator;
        denominator = -denominator;
    }

    cout << numerator << "/" << denominator;

    return 0;
}