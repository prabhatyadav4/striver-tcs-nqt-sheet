/*
Q13. Adding an Element in an Array

Array Insertion / Traversal

Constraints:

1 ≤ N ≤ 10^5
Array has enough capacity to accommodate one extra element.
0 ≤ Position ≤ N

Input Format:

First line contains integer N.
Second line contains N space-separated integers.
Third line contains:
    Element to insert X
    Position P (0-based index)

Output Format:

Print the array after inserting the element.

Sample Input:
5
1 2 3 4 5
10 2

Sample Output:
1 2 10 3 4 5

TCS Story Version:

A company stores employee IDs in an array.
A new employee joins and their ID must be inserted at a specific position in the existing list while maintaining the order of other IDs.

Key Observation:

Arrays have fixed positions.

To insert an element at position P:
    Shift all elements from P to N-1 one position to the right.
    Place the new element at index P.
*/

/*
Brute Force:    TC -> O(N)      SC -> O(N)

Algorithm:
1. Create a new array of size N+1.
2. Copy elements before position P.
3. Insert X at position P.
4. Copy remaining elements.
5. Print the new array.
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

    int x, p;
    cin >> x >> p;

    int temp[n + 1];

    for (int i = 0; i < p; i++)
    {
        temp[i] = arr[i];
    }

    temp[p] = x;

    for (int i = p; i < n; i++)
    {
        temp[i + 1] = arr[i];
    }

    for (int i = 0; i <= n; i++)
    {
        cout << temp[i] << " ";
    }

    return 0;
}

/*
Better:     TC -> O(N)      SC -> O(1)

Algorithm:
Using vector
    `. Insert at beginning.
    2. Insert at specific position.
    3. Push at end.
*/

#include <iostream>
#include <vector>
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

    int beginVal, pos, middleVal, endVal;
    cin >> beginVal >> pos >> middleVal >> endVal;

    // Insert at beginning
    arr.insert(arr.begin(), beginVal);

    // Insert at given position
    if (pos >= 0 && pos <= arr.size())
    {
        arr.insert(arr.begin() + pos, middleVal);
    }

    // Insert at end
    arr.push_back(endVal);

    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}

/*
Optimal:    TC -> O(N)      SC -> O(1)

Algorithm:
1. Read the array.
2. Start from the last element.
3. Shift elements one position right until position P.
4. Insert X at position P.
5. Increase size by 1.
6. Print the updated array.
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int x, p;
    cin >> x >> p;

    for (int i = n; i > p; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[p] = x;
    n++;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}