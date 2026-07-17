/*
Q46. Print Distinct Prime Factors of a Number

Topic:  Numbers

Difficulty: Easy

Pattern:    Prime Numbers / Prime Factorization

TCS Frequency:  High

Constraints:
2 ≤ N ≤ 10^12
Use long long for large inputs.

Input Format:
One number:    N

Output Format:
Print all distinct prime factors of N in increasing order.

Sample Input:
60

Sample Output:
2 3 5

Explanation:
Factors of 60 are:
1, 2, 3, 4, 5, 6, 10, 12, 15, 20, 30, 60

Among these, only 2, 3 and 5 are prime.

TCS Story Version:

A security system stores only the unique prime keys used to generate an encrypted number.

Given a number N, print all distinct prime factors in increasing order.

Mathematical Concept Used:

Prime Number
A prime number has exactly two factors:
1 and itself.

Fundamental Theorem of Arithmetic
Every positive integer greater than 1 can be expressed as the
product of prime numbers.

Example:

60 = 2 × 2 × 3 × 5

Distinct Prime Factors:
2 3 5

Key Observation

Every composite number has at least one factor less than or equal to √N.

Once a prime factor is found, remove all of its occurrences.
Print it only once.
*/
/*
Brute Force:        TC -> O(N√N)      SC -> O(1)

Algorithm:
1. Read N.
2. Traverse from 2 to N.
3. Check whether current number is prime.
4. If it is prime and divides N,
   print it once.
5. Remove all occurrences of that prime factor.
6. Continue.
*/

#include <iostream>
using namespace std;

bool isPrime(long long n)
{

    if (n < 2)
    {
        return false;
    }

    for (long long i = 2; i * i <= n; i++)
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
    long long n;
    cin >> n;

    for (long long i = 2; i <= n; i++)
    {
        if (isPrime(i) && n % i == 0)
        {
            cout << i << " ";

            while (n % i == 0)
            {
                n /= i;
            }
        }
    }

    return 0;
}

/*
Better:     TC -> O(√N log N)      SC -> O(1)

Algorithm:
1. Read N.
2. Traverse from 2 to √N.
3. If i divides N,
   print i once.
4. Remove all occurrences of i.
5. Continue searching.
6. If remaining N > 1,
   print it.
*/

#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    for (long long i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";

            while (n % i == 0)
            {
                n /= i;
            }
        }
    }

    if (n > 1)
    {
        cout << n;
    }

    return 0;
}

/*
Optimal:        TC -> O(√N)      SC -> O(1)

Algorithm:
1. Read N.
2. If 2 divides N,
   print 2 once.
3. Remove all factors of 2.
4. Check only odd numbers from 3 to √N.
5. Whenever a factor is found,
   print it once.
6. Remove all occurrences of that factor.
7. If remaining N > 2,
   print it.
*/

#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    if (n % 2 == 0)
    {
        cout << 2 << " ";

        while (n % 2 == 0)
        {
            n /= 2;
        }
    }

    for (long long i = 3; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";

            while (n % i == 0)
            {
                n /= i;
            }
        }
    }

    if (n > 2)
    {
        cout << n;
    }

    return 0;
}