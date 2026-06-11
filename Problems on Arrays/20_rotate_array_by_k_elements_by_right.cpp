/*
Q20. Rotate Array by K Elements to the Right

Topic: Arrays

Difficulty: Medium

Pattern: Array Rotation / Reversal Algorithm

Constraints:
1 ≤ N ≤ 10^5
0 ≤ K ≤ N
-10^9 ≤ arr[i] ≤ 10^9

Input Format:
First line contains integer N.
Second line contains N space-separated integers.
Third line contains integer K.

Output Format:
Print the array after rotating it right by K positions.

Sample Input:
7
1 2 3 4 5 6 7
2

Sample Output:
6 7 1 2 3 4 5

TCS Story Version:
A conveyor belt contains N products arranged in sequence.
Due to a change in production requirements, the last K products must be moved to the front while maintaining their relative order.
Rearrange the products accordingly.

Key Observation:
For right rotation by K:
[A][B]
where
A = first N-K elements
B = last K elements

Result should become:
[B][A]

The Reversal Algorithm swaps blocks efficiently without using extra space.
*/

/*
Brute Force:    TC -> O(N * K)      SC -> O(1)

Algorithm:
1. Rotate the array one position right, K times.
2. For each rotation:
   - Store the last element.
   - Shift remaining elements right.
   - Put the stored element at the first position.
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

    int k;
    cin >> k;

    k %= n;

    while (k--)
    {

        int last = arr[n - 1];

        for (int i = n - 1; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }

        arr[0] = last;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

/*
Better:     TC -> O(N)  SC -> O(N)

Algorithm:
1. Create a temporary array.
2. Copy the last K elements (from index N-K to N-1) to the temp array.
3. Copy the first N-K elements (from index 0 to N-K-1) to the temp array.
4. Print the temporary array.
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

    int k;
    cin >> k;

    k %= n;

    int temp[n];
    int index = 0;

    for (int i = n - k; i < n; i++)
    {
        temp[index++] = arr[i];
    }

    for (int i = 0; i < n - k; i++)
    {
        temp[index++] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << temp[i] << " ";
    }

    return 0;
}

/*
Optimal:    TC -> O(N)      SC -> O(1)

Algorithm:
1. Reverse the entire array (N elements).
2. Reverse the first K elements.
3. Reverse the remaining N-K elements.
*/

#include <iostream>
#include <algorithm>
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

    int k;
    cin >> k;

    k %= n;

    reverse(arr, arr + n);
    reverse(arr, arr + k);
    reverse(arr + k, arr + n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}