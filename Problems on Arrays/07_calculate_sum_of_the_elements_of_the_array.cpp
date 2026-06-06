/*
Calculate Sum of the Elements of the Array

Topic: Arrays

Difficulty: Easy

Pattern: Array Traversal / Accumulation

Constraints:
1 ≤ N ≤ 10^5
-10^9 ≤ arr[i] ≤ 10^9

Input Format:
First line contains integer N.
Second line contains N space-separated integers.

Output Format:
Print the sum of all elements in the array.

Sample Input:
5
1 2 3 4 5

Sample Output:
15

TCS Story Version:
A company records the daily sales of a product for N days.
The manager wants to calculate the total sales made during the entire period. Given the sales data, find the sum of all sales.

Key Observation:
The sum of an array can be obtained by traversing the array once and continuously adding each element to a running total.
*/

/*
Brute Force:    TC -> O(N)      SC -> O(1)

Algorithm:
1. Initialize sum = 0.
2. Traverse the array.
3. Add each element to sum.
4. Print sum.
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];

    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    cout << sum;

    return 0;
}

/*
Optimal:    TC -> O(N)  SC -> O(1)

Algorithm:
1. Most languages provide built-in functions or methods that efficiently sum all elements of an array.
2. Using these eliminates the need to write explicit loops, making code concise and sometimes faster due to optimized internal implementations.
3. Use the language's built-in sum or reduce function to get the sum of all elements.
4. Return the result directly.
*/

#include <iostream>
#include <numeric>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << accumulate(arr, arr + n, 0);

    return 0;
}