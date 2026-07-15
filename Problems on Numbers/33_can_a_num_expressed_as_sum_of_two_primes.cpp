/*
Q58. Check Whether a Number Can Be Expressed as the Sum of Two Prime Numbers

Topic: Numbers

Difficulty: Easy

Pattern: Prime Number / Pair Search

TCS Frequency: High

Problem Statement:

You are given a positive integer N.

Check whether N can be expressed as the sum of two prime numbers.

If such a pair exists, print the two prime numbers.

Otherwise, print:

Cannot be expressed as the sum of two prime numbers

A prime number is a number greater than 1 that has exactly two
factors: 1 and itself.

Input Format:

The input contains one positive integer N.

Output Format:

If N can be expressed as the sum of two prime numbers, print:

prime1 prime2

Otherwise, print:

Cannot be expressed as the sum of two prime numbers

Constraints:

1 <= N <= 10^9

Sample Input 1:

34

Sample Output 1:

3 31

Explanation:

Both 3 and 31 are prime numbers, and:

3 + 31 = 34

Therefore, 34 can be expressed as the sum of two prime numbers.

Sample Input 2:

17

Sample Output 2:

Cannot be expressed as the sum of two prime numbers

Explanation:

There is no pair of prime numbers whose sum is 17.

Sample Input 3:

10

Sample Output 3:

3 7

Explanation:

Both 3 and 7 are prime numbers, and:

3 + 7 = 10

Approach:

1. Traverse numbers from 2 to N / 2.
2. Let the first number be i.
3. Let the second number be N - i.
4. Check whether both numbers are prime.
5. If both are prime, print the pair and stop.
6. If no pair is found, print the failure message.

Why do we check only up to N / 2?

For every pair:

firstPrime + secondPrime = N

If the first prime becomes greater than N / 2, the same pairs start
appearing in reverse order.

For example, for N = 10:

3 + 7
7 + 3

Both represent the same pair, so checking up to N / 2 is sufficient.

Time Complexity:

The loop runs approximately N / 2 times, and each primality test
takes O(sqrt(N)) time.

Time Complexity: O(N * sqrt(N))

Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

bool isPrime(int n)
{
    if (n < 2)
    {
        return false;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int n;
    cin >> n;

    bool found = false;

    for (int i = 2; i <= n / 2; i++)
    {
        if (isPrime(i) && isPrime(n - i))
        {
            cout << i << " " << n - i;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Cannot be expressed as the sum of two prime numbers";
    }

    return 0;
}