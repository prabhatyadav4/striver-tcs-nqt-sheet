/*
Q1. Find the Smallest Number in an Array

Problem Analysis:

Topic: Arrays

Difficulty: Easy

Input Format:
First line contains an integer N (size of array).
Second line contains N space-separated integers.

Output Format:
Print the smallest element in the array.

Sample Input:
5
12 7 25 3 18

Sample Output:
3

TCS NQT Story-Based Version:

A warehouse manager records the weights of N products stored in the warehouse.
To identify the lightest product for shipping, find the minimum weight among all the products.
*/

// Brute Force: TC -> O(N log N)    SC -> O(1)

#include <iostream>
#include <vector>
#include <algorithm>
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

    sort(arr.begin(), arr.end());

    cout << arr[0];

    return 0;
}

// Optimal Solution: TC -> O(N)    SC -> O(1)

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

    int smallest = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            smallest = arr[i];
        }
    }

    cout << smallest;

    return 0;
}