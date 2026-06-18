/*
Q23. Sort an Array According to the Order Defined by Another Array

Topic:  Arrays

Difficulty: Medium

Pattern:    Hashing + Custom Sorting

Constraints:
1 ≤ N, M ≤ 10^5
-10^9 ≤ arr1[i], arr2[i] ≤ 10^9
Elements of arr2 are distinct.

Input Format:
First line contains integer N (size of first array).
Second line contains N space-separated integers (arr1).
Third line contains integer M (size of second array).
Fourth line contains M space-separated integers (arr2).

Output Format:
Print arr1 sorted according to the order specified in arr2.
Elements not present in arr2 should be placed at the end in ascending order.

Sample Input
11
2 1 2 5 7 1 9 3 6 8 8
4
2 1 8 3

Sample Output
2 2 1 1 8 8 3 5 6 7 9

Explanation
Order specified by arr2:
2 → first
1 → second
8 → third
3 → fourth

Remaining elements: 5 6 7 9 are sorted normally and placed at the end.

TCS Story Version:

A company prioritizes products according to a predefined ranking list.

Given:

    Product inventory (arr1)
    Priority order (arr2)

Arrange inventory so that products appear according to the company's priority list. Remaining products should appear afterward in increasing order.

Key Observation:

Normal sorting won't work because:

    Desired Order ≠ Numerical Order

We need:
    Frequency count of elements in arr1.
    Print elements following the order of arr2.
    Print remaining elements in sorted order.
*/

/*
Brute Force:    TC -> O(N X M)      SC -> O(N)

Algorithm
For every element in arr2:
    1. Traverse arr1.
    2. Print all matching elements.
    3. Mark them visited.

After processing arr2:
    1. Collect remaining elements.
    2. Sort them.
    3. Print them.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr1(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    int m;
    cin >> m;

    vector<int> arr2(m);
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    vector<bool> used(n, false);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr1[j] == arr2[i])
            {
                cout << arr1[j] << " ";
                used[j] = true;
            }
        }
    }

    vector<int> rem;

    for (int i = 0; i < n; i++)
    {
        if (!used[i])
        {
            rem.push_back(arr1[i]);
        }
    }

    sort(rem.begin(), rem.end());

    for (int x : rem)
    {
        cout << x << " ";
    }

    return 0;
}

/*
Optimal:    TC ->   O(N log N)  SC -> O(N)

Algorithm
Step 1: Store frequencies:  Value → Count
Step 2: Traverse arr2
        Print every element as many times as it appears.

Step 3: Remove printed elements from map.

Step 4: Store remaining elements.

Step 5: Sort remaining elements and print.
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

    vector<int> arr1(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    int m;
    cin >> m;

    vector<int> arr2(m);
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    unordered_map<int, int> freq;

    for (int x : arr1)
    {
        freq[x]++;
    }

    for (int x : arr2)
    {
        while (freq[x] > 0)
        {
            cout << x << " ";
            freq[x]--;
        }
    }

    vector<int> rem;

    for (auto p : freq)
    {
        while (p.second--)
        {
            rem.push_back(p.first);
        }
    }

    sort(rem.begin(), rem.end());

    for (int x : rem)
    {
        cout << x << " ";
    }

    return 0;
}