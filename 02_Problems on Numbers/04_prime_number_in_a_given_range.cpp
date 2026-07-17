/*
Q29. Prime Numbers in a Given Range

Topic:  Numbers

Difficulty: Easy

Pattern:    Range Traversal + Prime Checking

TCS Frequency:  Very High

Constraints:
1 ≤ L ≤ R ≤ 10^5 (Typical TCS Constraint)
Range may contain multiple prime numbers

Input Format:

Two integers:   L R

where:
L = Starting number
R = Ending number

Output Format:

Print all prime numbers present in the given range separated by spaces.

Sample Input:
10 30

Sample Output:
11 13 17 19 23 29

TCS Story Version:

A company assigns special security IDs to employees. An ID is considered special if it has exactly two factors: 1 and itself.

Given a range of employee IDs from L to R, find all special IDs.

Mathematical Concept Used:
Prime Numbers
Factors
Square Root Optimization

Key Observation:

A number N is prime if it has exactly two factors:  1 and N

Important Property:
If N is not prime, then at least one factor will exist less than or equal to √N.
Therefore, for each number, checking divisibility till √N is sufficient.
*/

/*
Brute Force:       TC -> O((R-L+1) × N)     SC -> O(1)
Algorithm:
1. Traverse every number from L to R.
2. Count factors from 1 to N.
3. If factor count equals 2, print the number.
*/

#include <iostream>
using namespace std;

int main()
{
    int L, R;
    cin >> L >> R;

    for (int i = L; i <= R; i++)
    {
        int count = 0;

        for (int j = 1; j <= i; j++)
        {

            if (i % j == 0)
            {
                count++;
            }
        }

        if (count == 2)
        {
            cout << i << " ";
        }
    }

    return 0;
}

/*
Optimal:    TC -> O((R-L+1) × √R)       SC -> O(1)

Algorithm:
1. Traverse numbers from L to R.
2. Ignore numbers less than 2.
3. For each number:
    Check divisibility from 2 to √N.
    If any divisor exists → Not Prime.
    Otherwise → Prime.
4. Print all prime numbers.
*/

#include <iostream>
using namespace std;

int main()
{
    int L, R;
    cin >> L >> R;

    for (int i = L; i <= R; i++)
    {

        if (i < 2)
        {
            continue;
        }

        bool isPrime = true;

        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                isPrime = false;
                break;
            }
        }

        if (isPrime)
        {
            cout << i << " ";
        }
    }

    return 0;
}