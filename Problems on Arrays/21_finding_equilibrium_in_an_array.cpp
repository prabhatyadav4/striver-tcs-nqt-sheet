/*
Q21. Finding Equilibrium Index in an Array

Topic:  Arrays

Difficulty: Easy-Medium

Pattern:    Prefix Sum

Constraints:
1 ≤ N ≤ 10^5
-10^9 ≤ arr[i] ≤ 10^9

Input Format:
First line contains integer N.
Second line contains N space-separated integers.

Output Format:
Print the Equilibrium Index.
If no equilibrium index exists, print: -1

Sample Input
5
1 3 5 2 2

Sample Output
2

Explanation:

At index 2:

Array = [1, 3, 5, 2, 2]

Left Sum  = 1 + 3 = 4
Right Sum = 2 + 2 = 4

Since both sums are equal, index 2 is the equilibrium index.

TCS Story Version

A company records profits earned over several days.

An equilibrium day is a day where:

Total profit before that day = Total profit after that day

Find the equilibrium day in the given profit record.

Key Observation

For every index:

Left Sum = Sum of elements before index i
Right Sum = Sum of elements after index i

If: Left Sum == Right Sum then i is the equilibrium index.
*/

/*
Brute Force:    TC -> O(N^2)    SC -> O(1)

Algorithm:

1. For every index:
    Compute left sum.
    Compute right sum.
    Compare both.

2. If equal, return index.
*/

#include <iostream>
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

    for (int i = 0; i < n; i++)
    {

        int leftSum = 0;
        for (int j = 0; j < i; j++)
        {
            leftSum += arr[j];
        }

        int rightSum = 0;
        for (int j = i + 1; j < n; j++)
        {
            rightSum += arr[j];
        }

        if (leftSum == rightSum)
        {
            cout << i;
            return 0;
        }
    }

    cout << "-1";

    return 0;
}

/*
Better:     TC -> O(N)      SC -> O(N)

Algorithm:
1. The idea is to remove the need of inner loop.
2. Instead of calculating the left side sum and right side sum each time, precompute the prefix sum array and suffix sum array, and simply access this in O(1) time.
3. So for each index i, we can check if prefixSum[i - 1] = suffixSum[i + 1] but to avoid unnecessary boundary checks we can also check if prefixSum[i] = suffixSum[i].
*/

#include <iostream>
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

    int prefixSum[n];
    int suffixSum[n];

    prefixSum[0] = arr[0];
    suffixSum[n - 1] = arr[n - 1];

    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        suffixSum[i] = suffixSum[i + 1] + arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (prefixSum[i] == suffixSum[i])
        {
            cout << i;
            return 0;
        }
    }

    cout << "-1";

    return 0;
}

/*
Optimal:    TC -> O(N)     SC -> O(1)

Algorithm:
Instead of storing a prefix array:
1. Calculate total sum.
2. Maintain leftSum = 0.
3. Traverse array:
    Remove current element from total sum.
    Now total sum becomes right sum.
    Compare leftSum and rightSum.
    Add current element to leftSum.
*/

#include <iostream>
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

    int totalSum = 0;

    for (int x : arr)
    {
        totalSum += x;
    }

    int leftSum = 0;

    for (int i = 0; i < n; i++)
    {
        int rightSum = totalSum - arr[i] - leftSum;

        if (leftSum == rightSum)
        {
            cout << i;
            return 0;
        }

        leftSum += arr[i];
    }

    cout << "-1";

    return 0;
}