/*
TCS NQT Coding 20 July 2026 Shift 2 (My Shift)

Q2. Longest Consecutive Sequence

Topic: Arrays / Hashing

Difficulty: Medium

Pattern: Searching / Consecutive Sequence

Problem Statement:

You are given an unsorted array containing N distinct integers.

Find the length of the longest sequence containing consecutive integer
values.

The consecutive values do not need to appear next to each other in the
original array.

Input Format:

The first line contains an integer N.

The second line contains N space-separated integers.

Output Format:

Print the length of the longest consecutive sequence.

Constraints:

1 <= N <= 10^5
-10^9 <= arr[i] <= 10^9
All array elements are distinct.

Sample Input:

6
5 4 3 11 12 13

Sample Output:

3

Brute Force Approach:

1. Consider every value as the possible starting element.
2. Search the complete array for the next consecutive value.
3. Continue until the next value is absent.
4. Store the maximum sequence length.

Time Complexity:    O(N^3) in the worst case

Space Complexity:   O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<long long> arr(n);

    for (long long &value : arr)
    {
        cin >> value;
    }

    if (n == 0)
    {
        cout << 0;
        return 0;
    }

    sort(arr.begin(), arr.end());

    int longestLength = 1;
    int currentLength = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
        {
            continue;
        }
        if (arr[i] == arr[i - 1] + 1)
        {
            currentLength++;
        }
        else
        {
            currentLength = 1;
        }

        longestLength = max(longestLength, currentLength);
    }

    cout << longestLength;

    return 0;
}