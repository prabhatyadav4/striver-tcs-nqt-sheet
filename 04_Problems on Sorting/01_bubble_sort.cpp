/*
Q68. Sort an Array Using Bubble Sort

Topic: Sorting

Difficulty: Easy

Pattern: Adjacent Comparison and Swapping

Problem Statement:

You are given an array of N integers.

Sort the array in ascending order using the Bubble Sort algorithm.

Bubble Sort repeatedly compares two adjacent elements. If the left
element is greater than the right element, the two elements are swapped.

Input Format:

The first line contains an integer N, representing the size of the array.

The second line contains N space-separated integers.

Output Format:

Print the elements of the sorted array in ascending order.

Constraints:

1 <= N <= 1000
-10^9 <= arr[i] <= 10^9

Sample Input:

5
5 1 4 2 8

Sample Output:

1 2 4 5 8

Approach:

1. Compare adjacent elements.
2. Swap elements that are in the wrong order.
3. Use a Boolean variable named swapped.
4. Set swapped to true whenever a swap occurs.
5. If no swap occurs during a complete pass, the array is sorted.
6. Stop the algorithm immediately.

Example:

Array:

1 2 3 4 5

During the first pass, no swap occurs.

Therefore, the algorithm stops after one pass instead of performing
all N - 1 passes.

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

    for (int i = 0; i < n - 1; i++)
    {

        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
        {
            break;
        }
    }

    for (int val : arr)
    {
        cout << val << " ";
    }

    return 0;
}