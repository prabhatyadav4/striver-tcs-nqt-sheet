/*
Q34. Sum of First N Natural Numbers

Topic:  Numbers

Difficulty: Easy

Pattern:    Mathematical Formula

TCS Frequency:  Very High

Constraints:
1 ≤ N ≤ 10^9
Use long long for large values of N

Input Format:
A single integer N.

Output Format:
Print the sum of the first N natural numbers.

Sample Input:
5

Sample Output:
15

TCS Story Version:

A company rewards employees based on their joining order.

Employee 1 gets 1 point.
Employee 2 gets 2 points.
Employee 3 gets 3 points.
...
Employee N gets N points.

Find the total reward points distributed among the first N employees.

Mathematical Concept Used:

Sum of First N Natural Numbers:

1 + 2 + 3 + ... + N

Formula: N × (N + 1) / 2

Key Observation:
Instead of adding numbers one by one, we can directly use:  Sum = N × (N + 1) / 2
This reduces the complexity from O(N) to O(1).
*/

/*
Brute Force:        TC -> O(N)      SC -> O(1)

Algorithm:
1. Initialize sum = 0.
2. Traverse from 1 to N.
3. Add each number to sum.
4. Print sum.
*/

#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    long long sum = 0;

    for (long long i = 1; i <= n; i++)
    {
        sum += i;
    }

    cout << sum;

    return 0;
}

/*
Optimal:     TC -> O(1)      SC -> O(1)

Algorithm:
1. Use the arithmetic progression formula.
2. Compute: N × (N + 1) / 2
3. Print the result.
*/

#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    long long sum = n * (n + 1) / 2;

    cout << sum;

    return 0;
}

/*
Recursive Approach:     TC -> O(N)      SC -> O(N)

Algorithm:
1. Define a recursive function sumNatural(n).
2. Base Case:   If n == 1, return 1.
3. Recursive Case:  Return n + sumNatural(n - 1).
4. The recursion continues until the base case is reached.
5. The returned values combine to produce the final sum.
*/

#include <iostream>
using namespace std;

long long sumNatural(long long n)
{
    if (n == 1)
    {
        return 1;
    }

    return n + sumNatural(n - 1);
}

int main()
{
    long long n;
    cin >> n;

    cout << sumNatural(n);

    return 0;
}