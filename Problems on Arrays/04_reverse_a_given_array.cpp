/*
Q4. Reverse a Given Array

Topic: Arrays

Difficulty: Easy

Pattern: Two Pointer / Array Traversal

Constraints:
1 ≤ N ≤ 10^5
-10^9 ≤ arr[i] ≤ 10^9

Input Format:
First line contains integer N.
Second line contains N space-separated integers.

Output Format:
Print the reversed array.

Sample Input:
5
1 2 3 4 5

Sample Output:
5 4 3 2 1

TCS Story Version:
A warehouse stores products in a sequence representing their loading order. Due to a change in shipping requirements, the order must be reversed before dispatch.
Given the sequence of products, reverse the order.

Key Observation:
To reverse an array, the first element must swap with the last, the second with the second-last, and so on.
This naturally leads to the Two Pointer approach.
*/

/*
Brute Force: TC -> O(N)     SC -> O(N)

Algorithm:
1. Create a new array.
2. Traverse the original array from the end to the beginning.
3. Store elements in the new array.
4. Print the new array.
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

    int rev[n];
    int j = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        rev[j++] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << rev[i] << " ";
    }

    return 0;
}

/*
Optimal: TC -> O(N)     SC -> O(1)

Algorithm:
1. Initialize two pointers:
    left = 0
    right = n - 1
2. Swap elements at left and right.
3. Move left++ and right--.
4. Continue until left < right.
5. Print the modified array.
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

    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}