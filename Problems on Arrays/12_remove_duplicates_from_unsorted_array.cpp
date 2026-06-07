/*
Q12. Remove Duplicates From an Unsorted Array

Topic:  Arrays

Difficulty: Easy-Medium

Pattern:    Hashing

Constraints:
1 ≤ N ≤ 10^5
-10^9 ≤ arr[i] ≤ 10^9

Input Format:
First line contains integer N.
Second line contains N space-separated integers.

Output Format:
Print the array after removing duplicates while preserving the first occurrence of each element.

Sample Input:
8
1 2 2 3 4 3 5 1

Sample Output:
1 2 3 4 5

TCS Story Version:

A company maintains a list of employee IDs collected from multiple departments.
Due to repeated entries, some IDs appear more than once.
Remove the duplicate IDs while keeping only their first occurrence.

Key Observation:

Unlike the sorted-array version, duplicates are not adjacent.

We need a way to quickly know whether an element has already appeared.

Hashing (unordered_set) is the most efficient approach.
*/

/*
Brute Force:    TC -> O(N^2)    SC -> O(1)

Algorithm:
1. For each element, check all previous elements.
2. If the element has not appeared before, print/store it.
3. Otherwise, skip it.
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

    for (int i = 0; i < n; i++)
    {
        bool found = false;

        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << arr[i] << " ";
        }
    }

    return 0;
}

/*
Optimal:    TC -> O(N)  SC -> O(N)

Algorithm:
1. Create an unordered_set.
2. Traverse the array.
3. If the element is not present in the set:
    Print/store it.
    Insert it into the set.
4. Otherwise skip it.
*/

#include <iostream>
#include <unordered_set>
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

    unordered_set<int> seen;

    for (int i = 0; i < n; i++)
    {
        if (seen.find(arr[i]) == seen.end())
        {
            cout << arr[i] << " ";
            seen.insert(arr[i]);
        }
    }

    return 0;
}