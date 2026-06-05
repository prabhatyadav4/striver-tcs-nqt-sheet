/*
Q2. Find the Largest element in an array

Problem Analysis:

Topic: Arrays

Difficulty: Easy

Input Format:

First line contains an integer N (size of array).
Second line contains N space-separated integers.

Output Format:

Print the largest element in the array.

Sample Input:
5
12 7 25 3 18

Sample Output:
25

TCS NQT Story-Based Version:

A company records the sales made by N employees in a month.
The management wants to identify the highest sales achieved by any employee.
Find the maximum sales value.
*/

// Brute Force: TC -> O(N log N)    SC -> O(N)

/*
Algorithm:

1. Sort the array in ascending order.
2. Print the element at the (size of the array - 1)th index, which corresponds to the largest element in the array.
*/

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

    cout << arr[n - 1];
}

// Optimal Solution: TC -> O(N)     SC -> O(1)

/*
Algorithm:

1. Create a variable called max and initialize it with the value of the first element in the array.
2. Use a for loop to iterate through the rest of the elements in the array.
3. In each iteration, compare the current element with the max variable.
4. If the current element is greater than the max value, update the max value with the current element's value.
5. After completing the loop, print the max variable, which will hold the largest value in the array.
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int largest = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (largest < arr[i])
        {
            largest = arr[i];
        }
    }

    cout << largest;

    return 0;
}