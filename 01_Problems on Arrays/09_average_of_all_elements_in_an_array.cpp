/*
Q9. Average of All the Elements in the Array

Topic:  Arrays

Difficulty: Easy

Pattern:    Array Traversal / Accumulation

Constraints:
1 ≤ N ≤ 10^5
-10^9 ≤ arr[i] ≤ 10^9

Input Format:
First line contains integer N.
Second line contains N space-separated integers.

Output Format:
Print the average of all elements in the array.

Sample Input:
5
1 2 3 4 5

Sample Output:
3

TCS Story Version:

A teacher records the marks of N students in a class. To evaluate the overall class performance, she wants to calculate the average marks scored by the students.

Key Observation:

Average is calculated as:
Average = Sum of Elements / N

First find the sum of all elements, then divide it by the number of elements.
*/

/*
Brute Force:    TC -> O(N)   SC -> O(1)

Algorithm:
1. Traverse the array and calculate the sum.
2. Divide the sum by N.
3. Print the result.
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    double avg = (double)sum / n;

    cout << avg;

    return 0;
}