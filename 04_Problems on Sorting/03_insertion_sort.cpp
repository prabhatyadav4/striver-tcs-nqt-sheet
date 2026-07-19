/*
Q70. Sort an Array Using Insertion Sort — Brute Force Solution

Topic: Sorting

Difficulty: Easy

Pattern: Adjacent Swapping / Sorted Prefix

Problem Statement:

You are given an array of N integers.

Sort the array in ascending order using the Insertion Sort algorithm.

Input Format:

The first line contains an integer N.

The second line contains N space-separated integers.

Output Format:

Print the sorted array in ascending order.

Constraints:

1 <= N <= 1000
-10^9 <= arr[i] <= 10^9

Sample Input:

5
5 2 4 6 1

Sample Output:

1 2 4 5 6

Approach:

1. Treat the first element as sorted.
2. Pick the current element as key.
3. Compare the key with elements on its left.
4. Shift every element greater than the key one position to the right.
5. Place the key in the empty position.

Example:

Array:

5 2 4 6 1

For key = 2:

5 is greater than 2, so shift 5 to the right.

Before:

5 2 4 6 1

After inserting 2:

2 5 4 6 1

Time Complexity:

Best Case:    O(N)
Average Case: O(N^2)
Worst Case:   O(N^2)

Space Complexity:   O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    for (int val : arr)
    {
        cout << val << " ";
    }

    return 0;
}