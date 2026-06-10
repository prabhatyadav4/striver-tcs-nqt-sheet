/*
Q14. Find All Repeating Elements in an Array

Topic:  Arrays

Difficulty: Easy-Medium

Pattern:    Hashing / Frequency Count

Constraints:
1 ≤ N ≤ 10^5
-10^9 ≤ arr[i] ≤ 10^9

Input Format:
First line contains integer N.
Second line contains N space-separated integers.

Output Format:
Print all elements that occur more than once in the array.

If no repeating element exists, print:

No Repeating Elements

Sample Input:
8
1 2 3 1 3 6 6 7

Sample Output:
1 3 6

TCS Story Version:

A company maintains a database of employee IDs. Due to synchronization issues, some IDs have been entered multiple times.
Find all employee IDs that appear more than once in the database.

Key Observation:

A repeating element is an element whose frequency is greater than 1.

Use a hash map to count frequencies efficiently and then print elements having frequency > 1.
*/

/*
Brute Force:    TC -> O(N^2)    SC -> O(N)

Algorithm:
1. For each element, count its occurrences by traversing the entire array.
2. Print elements whose count is greater than 1.
3. Use a visited mechanism to avoid printing duplicates multiple times.
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

    bool visited[n] = {false};

    bool found = false;

    for (int i = 0; i < n; i++)
    {

        if (visited[i])
            continue;

        int count = 1;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
                visited[j] = true;
            }
        }

        if (count > 1)
        {
            cout << arr[i] << " ";
            found = true;
        }
    }

    if (!found)
    {
        cout << "No repeating elements.";
    }

    return 0;
}

/*
Better:     TC -> O(N log N)    SC -> O(1)

Algorithm:
1. Sort the array.
2. Traverse the sorted array.
3. If adjacent elements are equal, print them once.
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

    bool found = false;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
        {
            cout << arr[i] << " ";
            found = true;

            while (i + 1 < n && arr[i] == arr[i + 1])
                i++;
        }
    }

    if (!found)
    {
        cout << "No repeating elements.";
    }

    return 0;
}

/*
Optimal:    TC -> O(N)      SC -> O(N)

Algorithm:
1. Create a frequency map using unordered_map.
2. Count occurrences of every element.
3. Traverse the array again.
4. Print elements whose frequency is greater than 1 only once.
*/

#include <iostream>
#include <unordered_map>
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

    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    unordered_set<int> printed;
    bool found = false;

    for (int i = 0; i < n; i++)
    {
        if (freq[arr[i]] > 1 && printed.find(arr[i]) == printed.end())
        {
            cout << arr[i] << " ";
            printed.insert(arr[i]);
            found = true;
        }
    }

    if (!found)
    {
        cout << "No repeating elements.";
    }

    return 0;
}