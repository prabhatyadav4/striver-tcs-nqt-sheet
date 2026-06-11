/*
Q18. Replace Elements by Its Rank in the Array

Topic:  Arrays

Difficulty: Easy-Medium

Pattern:    Sorting + Hashing

Constraints:
1 ≤ N ≤ 10^5
-10^9 ≤ arr[i] ≤ 10^9

Input Format:
First line contains integer N.
Second line contains N space-separated integers.

Output Format:
Replace every element with its rank and print the resulting array.

Rank Rule:
Smallest element gets rank 1.
Equal elements get the same rank.
Ranks increase by 1 for each new distinct element.

Sample Input:
6
20 15 26 2 98 6

Sample Output:
4 3 5 1 6 2

TCS Story Version:

A company evaluates employees based on performance scores.
Instead of storing actual scores, management wants to replace every score with its rank among all employees.
The lowest score gets rank 1, and employees with the same score receive the same rank.

Key Observation

To determine ranks:

1. Sort the elements.
2. Assign ranks to unique values.
3. Use a HashMap to store: Value → Rank
4. Traverse original array and replace each element by its rank.
*/

/*
Brute Force:    TC -> O(N^2)    SC -> O(1)

Algorithm:
1. For every element:
2. Count how many distinct elements are smaller than it.
    Rank = count + 1.
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

        int rank = 1;

        for (int j = 0; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                rank++;
            }
        }

        cout << rank << " ";
    }

    return 0;
}

/*
Optimal:    TC -> O(N log N)    SC -> O(N)

Algorithm:
1. Copy original array.
2. Sort copied array.
3. Traverse sorted array.
4. Assign rank to unique elements only.
5. Store ranks in HashMap.
6. Traverse original array and print mapped ranks.
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

    vector<int> sortedArr = arr;

    sort(sortedArr.begin(), sortedArr.end());

    unordered_map<int, int> rankMap;

    int rank = 1;

    for (int i = 0; i < n; i++)
    {
        if (rankMap.find(sortedArr[i]) == rankMap.end())
        {
            rankMap[sortedArr[i]] = rank;
            rank++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << rankMap[arr[i]] << " ";
    }

    return 0;
}