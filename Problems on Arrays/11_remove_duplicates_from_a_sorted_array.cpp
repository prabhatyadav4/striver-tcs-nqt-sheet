/*
Q11. Remove Duplicates In-Place from Sorted Array

Topic:  Arrays

Difficulty: Easy-Medium

Pattern:    Two Pointer

Constraints:
1 ≤ N ≤ 10^5
Array is already sorted.
-10^9 ≤ arr[i] ≤ 10^9

Input Format:
First line contains integer N.
Second line contains N space-separated sorted integers.

Output Format:
Print the array after removing duplicates and the new length.

Sample Input:
7
1 1 2 2 2 3 4

Sample Output:
1 2 3 4
Length = 4

TCS Story Version:

A company's employee database is sorted by employee ID.
Due to a synchronization issue, some IDs appear multiple times.
Remove duplicate IDs in-place while keeping only one occurrence of each employee ID.

Key Observation:

Since the array is already sorted, all duplicates appear adjacent to each other.
We can use:
    One pointer (i) to track the position of the last unique element.
    Another pointer (j) to scan the array.
Whenever a new unique element is found, place it at the next available position.
*/

/*
Brute Force:    TC -> O(N)      SC -> O(N)

Algorithm:
1. Traverse the array.
2. Insert unique elements into a set.
3. Copy set elements back into the array.
4. Print the modified array.
*/

#include <iostream>
#include <set>
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

    set<int> st;

    for (int i = 0; i < n; i++)
    {
        st.insert(arr[i]);
    }

    int index = 0;

    for (int x : st)
    {
        arr[index++] = x;
    }

    for (int i = 0; i < index; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\nLength = " << index;

    return 0;
}

/*
Optimal:    TC -> O(N)      SC-> O(1)

Algorithm:
1. Initialize i = 0.
2. Traverse the array using j from 1 to n-1.
3. If arr[j] != arr[i]:
    Increment i.
    Place arr[j] at arr[i].
4. New length becomes i + 1.
5. Print elements from index 0 to i.
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

    int i = 0;

    for (int j = 1; j < n; j++)
    {
        if (arr[i] != arr[j])
        {
            i++;
            arr[i] = arr[j];
        }
    }

    int newLen = i + 1;

    for (int k = 0; k < newLen; k++)
    {
        cout << arr[k];
    }

    cout << "\nLength = " << newLen;

    return 0;
}