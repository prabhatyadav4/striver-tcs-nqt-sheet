/*
Q36. Sum of GP Series

Topic:  Numbers

Difficulty: Easy

Pattern:    Geometric Progression (GP)

TCS Frequency:  Medium

Constraints:
1 ≤ a ≤ 10^9
0 ≤ r ≤ 10^9
1 ≤ n ≤ 10^5

Use long long for large values
If precise decimal answers are required, use double

Where:
a = First term
r = Common ratio
n = Number of terms

Input Format:
Three integers: a r n

where:
a = First term
r = Common ratio
n = Number of terms

Output Format:
Print the sum of the GP series.

Sample Input:
2 3 4

Sample Output:
80

TCS Story Version:

A company launches a referral program.

The first employee earns a reward points.
Every next employee earns r times the reward points of the previous employee.

Find the total reward points distributed among the first n employees.

Mathematical Concept Used:

Geometric Progression:  a, ar, ar², ar³, ...

Nth Term:   an = a × r^(n-1)

Sum of GP:

For r ≠ 1

S = a × (r^n - 1) / (r - 1)

Alternative Formula:

S = a × (1 - r^n) / (1 - r)

For r = 1

S = a × n

Key Observation:
Instead of generating every term individually, we can directly use the GP sum formula.
This reduces complexity from O(N) to O(log N) (because of power calculation).
*/

/*
Brute Force:        TC -> O(N)      SC -> O(1)

Algorithm:
1. Initialize sum = 0.
2. Generate each GP term.
3. Add each term to sum.
4. Print the final sum.
*/

#include <iostream>
using namespace std;

int main()
{
    long long a, r, n;
    cin >> a >> r >> n;

    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += a;
        a *= r;
    }

    cout << sum;

    return 0;
}

/*
Optimal:    TC -> O(log N)      SC -> O(1)

Algorithm:
1. If r == 1
    Sum = a × n
2. Otherwise:
    Compute r^n
3. Apply GP sum formula.
4. Print result.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long a, r, n;
    cin >> a >> r >> n;

    long long sum;

    if (r == 1)
    {
        sum = a * n;
    }
    else
    {
        sum = a * (pow(r, n) - 1) / (r - 1);
    }

    cout << sum;

    return 0;
}