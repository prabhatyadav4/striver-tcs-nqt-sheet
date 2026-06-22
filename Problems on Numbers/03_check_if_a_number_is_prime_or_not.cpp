/*
Q28. Check if a Number is Prime or Not

Topic:  Numbers

Difficulty: Easy

Pattern:    Prime Number Check using Divisibility

TCS Frequency:  Very High

Constraints:
1 ≤ N ≤ 10^9 (typically in TCS NQT)
Input is a positive integer

Input Format:

A single integer N.

Output Format:

Print:
    "Prime" if the number is prime
    "Not Prime" otherwise

Sample Input:
13

Sample Output:
Prime

TCS Story Version:

A company assigns a special security level to employee IDs. An ID is considered special if it has exactly two factors: 1 and itself.

Given an employee ID number, determine whether it qualifies as a special ID.

Mathematical Concept Used:

Factors of a Number
Divisibility Rules
Square Root Optimization

Key Observation:

A prime number has exactly two factors: 1 and itself

Examples:

2 → Prime
3 → Prime
5 → Prime
7 → Prime
11 → Prime

Non-prime:

4 = 2 × 2
6 = 2 × 3
8 = 2 × 4

Important Observation:

If a number N is composite, at least one factor must exist less than or equal to √N.
Therefore, checking till √N is sufficient.
*/

/*
Brute Force:    TC -> O(N)      SC -> O(1)

Algorithm:
1. Count factors from 1 to N.
2. If factor count equals 2, number is prime.
3. Otherwise not prime.
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n < 2)
    {
        cout << "Not Prime";
        return 0;
    }

    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            count++;
        }
    }

    if (count == 2)
    {
        cout << "Prime";
    }
    else
    {
        cout << "Not Prime";
    }

    return 0;
}

/*
Optimal:    TC -> O(N^1/2)      SC -> O(1)
Algorithm:
1. If N < 2 → Not Prime.
2. Traverse from 2 to √N.
3. If any number divides N completely:
    Not Prime.
4. Otherwise:
    Prime.
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n < 2)
    {
        cout << "Not Prime";
        return 0;
    }

    bool isPrime = true;

    for (int i = 2; i * i <= n; i++)        
    {
        if (n % i == 0)
        {
            isPrime = false;
            break;
        }
    }

    if (isPrime)
    {
        cout << "Prime";
    }
    else
    {
        cout << "Prime";
    }

    return 0;
}