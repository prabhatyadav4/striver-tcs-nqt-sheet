/*
Q22. Finding Circular Rotation of an Array by K Positions

Topic:  Arrays

Difficulty: Easy-Medium

Pattern:    Array Rotation / Modulo Arithmetic

Constraints:
1 ≤ N ≤ 10^5
0 ≤ K ≤ 10^9
-10^9 ≤ arr[i] ≤ 10^9

Input Format:
First line contains integer N.
Second line contains N space-separated integers.
Third line contains integer K.

Output Format:
Print the array after circular rotation by K positions.

Sample Input
5
1 2 3 4 5
2

Sample Output (Right Circular Rotation)
4 5 1 2 3

TCS Story Version

A company maintains employee shifts in a circular schedule.
Every K days, the schedule rotates and employees move to new positions.
Since the schedule is circular, employees shifted beyond the end reappear at the beginning.
Determine the updated schedule after K rotations.

Key Observation:

1. Circular rotation means: Last elements wrap around to the front
    Example:
        Array = 1 2 3 4 5
        K = 2

2. After rotation: 4 5 1 2 3

3. Always reduce rotations using:  K = K % N;  because: Rotating N times = Original Array
*/

/*
Brute Force:    TC -> O(N * K)     SC -> O(1)

Algorithm:
1. Rotate one position at a time.
2. For each rotation:
    Store last element.
    Shift all elements right.
    Put stored element at index 0.
3. Repeat K times.
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
Brute:      TC -> O(N)      SC -> O(K)

Algorithm:
1. Store last K elements in a temporary array.
2. Shift remaining elements right.
3. Copy temporary elements at the beginning.
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
1. Reverse whole array.
2. Reverse first K elements.
3. Reverse remaining N-K elements.
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

    reverse(arr, arr + n);
    reverse(arr, arr + k);
    reverse(arr + k, arr + n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

/*
Optimal (Modulo Mapping):   TC -> O(N)  SC -> O(N)

Algorithm:

1. For each index: newIndex = (i + K) % N
2. Place element at its new position.
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

    int ans[n];

    for (int i = 0; i < n; i++)
    {
        ans[(i + k) % n] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}