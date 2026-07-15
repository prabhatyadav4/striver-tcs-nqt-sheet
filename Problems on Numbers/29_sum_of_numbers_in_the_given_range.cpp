/*
Q54. Find the Sum of Numbers in the Given Range — Brute Force

Topic: Numbers

Difficulty: Easy

Pattern: Range Traversal

Problem Statement:

You are given two integers L and R representing the starting and ending
values of a range.

Find the sum of all integers from L to R, including both L and R.

Input Format:

The input contains two space-separated integers L and R.

Output Format:

Print the sum of all numbers from L to R.

Constraints:

1 <= L <= R <= 10^9

Sample Input:

5 10

Sample Output:

45

Explanation:

The numbers from 5 to 10 are:

5, 6, 7, 8, 9, 10

Their sum is:

5 + 6 + 7 + 8 + 9 + 10 = 45

Brute Force Approach:

1. Initialize sum as 0.
2. Traverse every number from L to R.
3. Add each number to sum.
4. Print the final sum.

Time Complexity:    O(R - L + 1)

Space Complexity:   O(1)
*/

#include <iostream>
using namespace std;

int main()
{
    long long left, right;
    cin >> left >> right;

    long long sum = 0;

    for (int i = left; i <= right; i++)
    {
        sum += i;
    }

    cout << sum;

    return 0;
}

/*
Optimal Solution

Approach:

The sum of the first N natural numbers is:

N * (N + 1) / 2

To calculate the sum from L to R:

Sum(L to R) = Sum(1 to R) - Sum(1 to L - 1)

Therefore:

Sum(L to R)
= R * (R + 1) / 2 - (L - 1) * L / 2

Example:

L = 5, R = 10

Sum from 1 to 10:

10 * 11 / 2 = 55

Sum from 1 to 4:

4 * 5 / 2 = 10

Sum from 5 to 10:

55 - 10 = 45

Time Complexity:    O(1)

Space Complexity:   O(1)
*/

#include <iostream>
using namespace std;

long long sumOfFirstNumber(long long n)
{
    return n * (n + 1) / 2;
}

int main()
{
    long long left, right;
    cin >> left >> right;

    long long sumTillRight = sumOfFirstNumber(right);
    long long sumBeforeLeft = sumOfFirstNumber(left - 1);
    long long rangeSum = sumTillRight - sumBeforeLeft;

    cout << rangeSum;

    return 0;
}