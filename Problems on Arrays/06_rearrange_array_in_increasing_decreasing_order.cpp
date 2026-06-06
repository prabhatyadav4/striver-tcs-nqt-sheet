/*
Q6. Rearrange Array in Increasing-Decreasing Order

Topic: Arrays

Difficulty: Easy-Medium

Pattern: Sorting

Constraints:
1 ≤ N ≤ 10^5
-10^9 ≤ arr[i] ≤ 10^9

Input Format:
First line contains integer N.
Second line contains N space-separated integers.

Output Format:
Rearrange the array such that:
    First half is in increasing order.
    Second half is in decreasing order.

Sample Input:
8
1 2 3 4 5 6 7 8

Sample Output:
1 2 3 4 8 7 6 5

TCS Story Version:
A warehouse manager wants to arrange products on shelves.
The lighter products should be arranged in increasing order on the first half of the shelf, while the heavier products should be arranged in decreasing order on the second half.
Rearrange the given product weights accordingly.

Key Observation:
Sort the array first.
Keep the first half as it is (increasing order).
Print the second half in reverse order (decreasing order).
*/

/*
Brute Force: TC -> O(N log N)   SC -> O(N);

Algorithm:
1. Sort the array.
2. Store the first half in one array.
3. Store the second half in reverse order in another array.
4. Merge and print.
*/

#include <iostream>
#include <vector>
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

    vector<int> ans;

    for (int i = 0; i < n / 2; i++)
    {
        ans.push_back(arr[i]);
    }

    for (int i = n - 1; i >= n / 2; i--)
    {
        ans.push_back(arr[i]);
    }

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}

/*
Better: TC -> O(N log N)    SC -> O(1)

Algorithm:
1. Since we need to arrange the first half in ascending order and second half in descending order, we have to first sort the entire array to convert both the halves in ascending order.
2. Now, to arrange the second half in descending order, we can simply reverse all the elements of second half as they are already arranged in ascending order.
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

    reverse(arr + n / 2, arr + n);

    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}

/*
Optimal:    TC -> O(N log N)    SC -> O(1)

Algorithm:
1. Sort the array.
2. Print the first (n+1)/2 elements in increasing order.
3. Print the remaining elements in reverse order.
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

    for (int i = 0; i < n / 2; i++)
    {
        cout << arr[i] << " ";
    }

    for (int i = n - 1; i >= n / 2; i--)
    {
        cout << arr[i] << " ";
    }

    return 0;
}