/*
Q43. Factorial of a Number

Topic:  Numbers

Difficulty: Easy

Pattern:    Iterative Multiplication / Recursion

TCS Frequency:  Very High

Constraints:
0 ≤ N ≤ 20

Use long long since 20! fits within a 64-bit signed integer.

Input Format:   A single integer N.

Output Format:  Print the factorial of N.

Sample Input:
5

Sample Output:
120

TCS Story Version:

A company assigns tasks where each task can be arranged in multiple ways. Given N distinct tasks, find the total number of possible arrangements.

This is equal to N! (N Factorial).

Mathematical Concept Used:

Factorial:  N! = N × (N-1) × (N-2) × ... × 2 × 1

Special Case:   0! = 1

Examples:

5! = 5 × 4 × 3 × 2 × 1 = 120

4! = 24

3! = 6

Key Observation:

Factorial is the product of all positive integers from 1 to N.

For N = 0 and N = 1, the factorial is always 1.
*/

/*
Brute Force:      TC -> O(N)      SC -> O(N)

Algorithm:
1. The factorial of a number N can be calculated by multiplying all natural numbers from 1 to N.
2. We can visualize this using recursion:
    factorial(N) = N * factorial(N - 1)
3. This means the factorial of N is the product of N and the factorial of N - 1.
4. We define a base case:
    If N == 0, we return 1, since 0! = 1 by definition.
5. This approach breaks the problem into smaller subproblems, and the results of each subproblem are multiplied together as the recursive calls return.
6. The final result is stored and printed as the output of the factorial(N) function.
*/

#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

int main()
{
    int n;
    cin >> n;

    cout << factorial(n);

    return 0;
}

/*
Optimal:        TC -> O(N)      SC -> O(1)

Algorithm:
1. If N == 0 or N == 1, print 1.
2. Otherwise:
    Initialize fact = 1.
    Multiply numbers from 2 to N.
3. Print the factorial.
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int fact = 1;

    for (int i = 2; i <= n; i++)
    {
        fact *= i;
    }

    cout << fact;

    return 0;
}