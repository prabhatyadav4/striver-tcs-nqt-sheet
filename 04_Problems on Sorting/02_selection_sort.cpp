/*
Q69. Sort an Array Using Selection Sort — Brute Force Solution

Topic: Sorting

Difficulty: Easy

Pattern: Minimum Element Selection

Problem Statement:

You are given an array containing N integers.

Sort the array in ascending order using the Selection Sort algorithm.

Input Format:

The first line contains an integer N, representing the size of the array.

The second line contains N space-separated integers.

Output Format:

Print the sorted array in ascending order.

Constraints:

1 <= N <= 1000
-10^9 <= arr[i] <= 10^9

Sample Input:

5
64 25 12 22 11

Sample Output:

11 12 22 25 64

Approach:

1. Divide the array into:
   - Sorted part
   - Unsorted part

2. Find the smallest element from the unsorted part.

3. Store the index of the smallest element.

4. Swap it with the first element of the unsorted part.

5. Repeat until the array is sorted.

Example:

Array:

64 25 12 22 11

Pass 1:

Minimum element = 11

Swap 64 and 11:

11 25 12 22 64

Pass 2:

Minimum element from remaining array = 12

Swap 25 and 12:

11 12 25 22 64

Time Complexity:

Best Case:    O(N^2)
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

    for (int i = 0; i < n - 1; i++)
    {

        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {

            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
    }

    for (int val : arr)
    {
        cout << val << " ";
    }

    return 0;
}