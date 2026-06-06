/*
Rotate Array by K Elements (Block Swap Algorithm)

Topic: Arrays

Difficulty: Medium

Pattern: Array Rotation / Divide & Conquer

Constraints:
1 ≤ N ≤ 10^5
0 ≤ K ≤ N
-10^9 ≤ arr[i] ≤ 10^9

Input Format:
First line contains integer N.
Second line contains N space-separated integers.
Third line contains integer K.

Output Format:
Print the array after rotating it left by K positions.

Sample Input:
7
1 2 3 4 5 6 7
2

Sample Output:
3 4 5 6 7 1 2

TCS Story Version:
A conveyor belt contains N products arranged in sequence.
Due to a change in production requirements, the first K products must be moved to the end while maintaining their relative order.
Rearrange the products accordingly.

Key Observation:
For left rotation by K:
[A][B]
where
A = first K elements
B = remaining N-K elements

Result should become:
[B][A]

The Block Swap Algorithm swaps blocks recursively without using extra space.
*/

/*
Brute Force:    TC -> O(N * K)      SC -> O(1)

Algorithm:
1. Rotate the array one position left, K times.
2. For each rotation:
3. Store first element.
4. Shift remaining elements left.
5. Put stored element at the end.
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
        int first = arr[0];

        for (int i = 0; i < n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        arr[n - 1] = first;
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
2. Copy elements from index K to N-1.
3. Copy elements from index 0 to K-1.
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

    for (int i = k; i < n; i++)
    {
        temp[index++] = arr[i];
    }

    for (int i = 0; i < k; i++)
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
1. Reverse first d elements
2. Reverse remaining n-d elements
3. Reverse whole array
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

    reverse(arr, arr + k);
    reverse(arr + k, arr + n);
    reverse(arr, arr + n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}