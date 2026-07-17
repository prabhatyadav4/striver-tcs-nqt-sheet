/*
Q35. Find Sum of AP Series

Topic:  Numbers

Difficulty: Easy

Pattern:    Arithmetic Progression (AP)

TCS Frequency:  High

Constraints:
1 ≤ a ≤ 10^9
1 ≤ d ≤ 10^9
1 ≤ n ≤ 10^6

Use long long to avoid overflow

Where:
a = First term
d = Common difference
n = Number of terms

Input Format:
Three integers: a d n

where:
a = First term
d = Common difference
n = Number of terms

Output Format:
Print the sum of the AP series.

Sample Input:
2 3 5

Sample Output:
40

TCS Story Version:

A company gives incentives to employees.

First employee gets a points.
Every next employee gets d more points than the previous one.

For the first n employees, find the total incentive points distributed.

Mathematical Concept Used:

Arithmetic Progression: a, a+d, a+2d, a+3d, ...

Nth Term:   an = a + (n-1)d

Sum of AP:  S = n/2 × [2a + (n-1)d]

Key Observation:
Instead of generating every term and adding them, we can directly use the AP sum formula:   S = n × (2a + (n-1)d) / 2
This reduces complexity from O(N) to O(1).
*/

/*
Brute Force:        TC -> O(N)      SC -> O(1)

Algorithm:
1. Initialize sum = 0.
2. Generate all N terms of AP.
3. Add every term to sum.
4. Print sum.
*/

#include <iostream>
using namespace std;

int main()
{
    long long a, d, n;
    cin >> a >> d >> n;

    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += a;
        a += d;
    }

    cout << sum;

    return 0;
}

/*
Optimal:        TC -> O(1)      SC -> O(1)

Algorithm
1. Use the formula for the sum of an A.P. series: Sum = n/2 * (2a + (n - 1) * d), where:
    n is the number of terms in the series.
    a is the first term of the series.
    d is the common difference between terms.
2. Substitute the values of a, d, and n into the formula to calculate the sum.
*/

#include <iostream>
using namespace std;

int main()
{
    long long a, d, n;
    cin >> a >> d >> n;

    long long sum = n * (2 * a + (n - 1) * d) / 2;

    cout << sum;

    return 0;
}