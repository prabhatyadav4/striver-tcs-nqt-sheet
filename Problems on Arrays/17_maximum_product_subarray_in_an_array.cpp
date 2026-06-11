/*
Q17. Maximum Product Subarray in an Array

Topic:  Arrays

Difficulty: Medium-Hard

Pattern:    Prefix-Suffix Traversal

Constraints:
1 ≤ N ≤ 10^5
-10^9 ≤ arr[i] ≤ 10^9

Input Format:
First line contains integer N.
Second line contains N space-separated integers.

Output Format:
Print the maximum product of any contiguous subarray.

Sample Input:
4
2 3 -2 4

Sample Output:
6

TCS Story Version:

A company tracks daily profit multipliers for a product.
A continuous period of days can be selected for a marketing campaign.
Find the contiguous period that yields the maximum overall profit multiplier.

Key Observation:

1. Unlike Maximum Sum Subarray:    Negative × Negative = Positive

2. A very small negative product can suddenly become the largest positive product when multiplied by another negative number.

3. Therefore, we must track:
    Maximum product ending at current index
    Minimum product ending at current index
*/

/*
Brute Force:    TC -> O(N^2)    SC -> O(1)

Algorithm:
1. Generate all possible subarrays.
2. Compute product for every subarray.
3. Keep track of maximum product.
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

    long long maxProduct = LLONG_MIN;

    for (int i = 0; i < n; i++)
    {

        long long product = 1;

        for (int j = i; j < n; j++)
        {
            product *= arr[j];
            maxProduct = max(maxProduct, product);
        }
    }

    cout << maxProduct;

    return 0;
}

/*
Optimal:    TC -> O(N)      SC -> O(1)

Algorithm (Prefix-Suffix):

1. Traverse from left and maintain prefix product.
2. Traverse from right and maintain suffix product.
3. Reset product to 1 whenever product becomes 0.
4. Maximum among all prefix and suffix products is the answer.
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

    long long maxProduct = INT_MIN;
    long long prefix = 1;
    long long suffix = 1;

    for (int i = 0; i < n; i++)
    {
        if (prefix == 0)
            prefix = 1;
        if (suffix == 0)
            suffix = 1;

        prefix *= arr[i];
        suffix *= arr[n - i - 1];

        maxProduct = max(maxProduct, max(prefix, suffix));
    }

    cout << maxProduct;

    return 0;
}