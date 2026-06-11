/*
Q19. Sort Elements of an Array by Frequency

Topic:  Arrays

Difficulty: Medium

Pattern:    Hashing + Custom Sorting

Constraints:
1 ≤ N ≤ 10^5
-10^9 ≤ arr[i] ≤ 10^9

Input Format:
First line contains integer N.
Second line contains N space-separated integers.

Output Format:
Print the array elements sorted in decreasing order of frequency.
If two elements have the same frequency, print the smaller element first (most common TCS convention).

Sample Input:
10
2 5 2 8 5 6 8 8 5 8

Sample Output:
8 8 8 8 5 5 5 2 2 6

TCS Story Version:

An e-commerce company analyzes product purchases.
Products purchased more frequently should appear first in the report.
If two products have been purchased the same number of times, the product with the smaller ID should appear first.
Sort all product IDs according to their purchase frequency.

Key Observation

We need two things:

1. Frequency of every element.
2. Custom sorting based on:
    Higher frequency first.
    Smaller value first when frequencies are equal.

This is a classic: HashMap + Custom Comparator problem.
*/

/*
Optimal:    TC -> O(N log N)    SC -> O(N)

Algorithm:
1. Create frequency map.
2. Sort the original array using:
    Higher frequency first.
    Smaller element first if frequencies match.
3. Print sorted array.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
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

    unordered_map<int, int> freq;

    for (int x : arr)
    {
        freq[x]++;
    }

    sort(arr.begin(), arr.end(), [&](int a, int b)
         {
        if(freq[a] == freq[b]) {
            return a < b;
        }

        return freq[a] > freq[b]; });

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}