/*
Q24. Search an Element in an Array

Topic:  Arrays

Difficulty: Easy

Pattern:    Linear Search / Binary Search

Constraints:
1 ≤ N ≤ 10^5
-10^9 ≤ arr[i] ≤ 10^9

Input Format:
First line contains integer N.
Second line contains N space-separated integers.
Third line contains the element X to be searched.

Output Format:
Print the index of the element if found.
If the element is not present, print:   -1

Sample Input
5
10 20 30 40 50
30

Sample Output
2

Explanation
Array = [10,20,30,40,50]

30 is present at index 2.

TCS Story Version

A company stores employee IDs in an array. Given an employee ID, determine whether it exists in the database and return its position.

Key Observation

For an unsorted array:

    Check every element one by one

This is called Linear Search.

If the array is sorted, Binary Search can be used for better efficiency.
*/

/*
Brute Force:    TC -> O(N)      SC -> O(1)

Algorithm:
1. Traverse the array from left to right.
2. Compare each element with X.
3. If found, print index.
4. Otherwise print -1.
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

    int x;
    cin >> x;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            cout << i;
            return 0;
        }
    }

    cout << "-1";

    return 0;
}

/*
Optimal (For Sorted Array):     TC -> O(log N)      SC -> O(1)

Algorithm:
1. Initialize:
    low = 0
    high = n-1
2. Find middle element.
3. If middle element equals X, return index.
4. If X is smaller, search left half.
5. Otherwise search right half.
6. Repeat until found or range becomes invalid.
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

    int x;
    cin >> x;

    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
        {
            cout << mid;
            return 0;
        }

        if (arr[mid] < x)
        {
            low = mid + 1;
        }

        else
        {
            high = mid - 1;
        }
    }

    cout << "-1";

    return 0;
}