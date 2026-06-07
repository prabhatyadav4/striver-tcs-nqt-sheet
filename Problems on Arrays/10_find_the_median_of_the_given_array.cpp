/*
Q10. Find the Median of the Given Array

Topic:  Arrays

Difficulty: Easy-Medium

Pattern:    Sorting

Constraints:
1 ≤ N ≤ 10^5
-10^9 ≤ arr[i] ≤ 10^9

Input Format:
First line contains integer N.
Second line contains N space-separated integers.

Output Format:
Print the median of the array.

Sample Input:
5
1 3 2 5 4

Sample Output:
3

TCS Story Version:

A school wants to analyze the performance of students based on their marks. Instead of using the average, which can be affected by very high or very low scores, the principal decides to use the median score.
Given the marks of all students, find the median.

Key Observation:

The median is the middle element of a sorted array.

If N is odd → Median = middle element.
If N is even → Median = average of the two middle elements.

Before finding the median, the array must be sorted.
*/

/*
Brute Force:    TC -> O(N log N)    SC -> O(1)

Algorithm:
1. Sort the array in ascending order.
2. If N is odd:
        Median = element at index N/2.
3. If N is even:
        Median = average of the two middle elements.
4. Print the median.
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

    sort(arr, arr + n);

    if (n % 2 == 1)
    {
        cout << arr[n / 2];
    }
    else
    {
        cout << (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    }

    return 0;
}