/*
Q42. Print Fibonacci Series up to Nth Term

Topic:  Numbers

Difficulty: Easy

Pattern:    Series Generation

TCS Frequency:  Very High

Constraints:
1 ≤ N ≤ 90
Use long long because Fibonacci numbers grow rapidly.

Note: Here, N represents the number of terms, not the maximum value.

Input Format:
A single integer N representing the number of Fibonacci terms to print.

Output Format:
Print the first N terms of the Fibonacci series separated by spaces.

Sample Input:
7

Sample Output:
0 1 1 2 3 5 8

TCS Story Version:

A company predicts its monthly user growth using the Fibonacci pattern.

The first two months have:
Month 1 → 0 users
Month 2 → 1 user

Every subsequent month, the number of users is the sum of the previous two months.

Given N, print the first N months' user growth.

Mathematical Concept Used:

Fibonacci Series:   0, 1, 1, 2, 3, 5, 8, 13, ...

Formula:    F(n) = F(n-1) + F(n-2)

Base Cases:
F(0) = 0
F(1) = 1

Key Observation:
Each Fibonacci number depends only on the previous two numbers.
Instead of storing the entire series, we only need the last two values.
*/

/*
Brute Force:    TC -> O(2^N)    SC -> O(N)

Algorithm:
1. Use recursion to calculate the nth Fibonacci number.
2. Call the recursive function for every term from 0 to N−1.
3. Print each result.
*/

#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << fibonacci(i) << " ";
    }
}

/*
Better:     TC -> O(N)      SC -> O(N)

Algorithm:
1. Create an array of size N.
2. Store:
    First term = 0
    Second term = 1
3. Generate remaining terms using:
    arr[i] = arr[i-1] + arr[i-2]
4. Print the array.
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> fib(n);

    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    for (int num : fib)
    {
        cout << num << " ";
    }

    return 0;
}

/*
Optimal:        TC -> O(N)      SC -> O(1)

Algorithm:
1. Read N.
2. Handle:
    N = 1 → Print 0
    N = 2 → Print 0 1
3. Initialize:
    first = 0
    second = 1
4. Print first and second.
5. Repeat from the 3rd term to the Nth term:
    third = first + second
6. Print third
7. Update:
    first = second
    second = third
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n <= 0)
    {
        return 0;
    }

    if (n == 1)
    {
        cout << 0;
        return 0;
    }

    int first = 0;
    int second = 1;

    cout << first << " " << second << " ";

    for (int i = 3; i <= n; i++)
    {
        int third = first + second;
        cout << third << " ";
        first = second;
        second = third;
    }

    return 0;
}