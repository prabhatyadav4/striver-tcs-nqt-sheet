/*
Q25. Check Whether Arr1 is a Subset of Arr2

Topic:  Arrays

Difficulty: Easy-Medium

Pattern:    Hashing / Set Operations

Constraints:
1 ≤ N, M ≤ 10^5
-10^9 ≤ arr[i] ≤ 10^9

Input Format:
First line contains integer N (size of arr1).
Second line contains N space-separated integers.
Third line contains integer M (size of arr2).
Fourth line contains M space-separated integers.

Output Format:

Print:  Yes

if arr1 is a subset of arr2, otherwise print:   No

Sample Input
3
11 3 1
5
11 1 13 21 3

Sample Output
Yes

Explanation

All elements of:

arr1 = [11,3,1]

are present in:

arr2 = [11,1,13,21,3]

Therefore, arr1 is a subset of arr2.

TCS Story Version

A company has a list of employees assigned to a project (arr1) and a master employee database (arr2).

Determine whether every employee assigned to the project exists in the master database.

Key Observation

To verify subset:

    Every element of arr1
    must be present in arr2

Hashing provides O(1) average lookup.
*/

/*
Brute Force:    TC -> O(N X M)    SC -> O(1)

Algorithm:

1. For every element of arr1:
    Search it in arr2.
2. If any element is not found:
    Print "No".
3. Otherwise print "Yes".
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr1[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    int m;
    cin >> m;

    int arr2[m];
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    for (int i = 0; i < n; i++)
    {
        bool found = false;

        for (int j = 0; j < m; j++)
        {
            if (arr1[i] == arr2[j])
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
}

/*
Optimal:    TC -> O(N + M)      SC -> O(M)

Algorithm:
1. Store all elements of arr2 in an unordered_set.
2. Check each element of arr1.
3. If every element exists in the set:
        arr1 is a subset of arr2.
4. Otherwise:
        arr1 is not a subset.
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

    unordered_set<int> st;

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        st.insert(x);
    }

    for (int i = 0; i < n; i++)
    {
        if (st.find(arr[i]) == st.end())
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
}