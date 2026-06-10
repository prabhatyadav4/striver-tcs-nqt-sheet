/*
Q15. Find All Non-Repeating Elements in an Array

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

Print all elements that occur exactly once in the array.

If no such element exists, print:

No Non-Repeating Elements

Sample Input:
8
1 1 2 3 4 4 5 2

Sample Output:
3 5

TCS Story Version:

A company maintains a database of employee IDs.
Some IDs appear multiple times due to duplicate records.
Find all employee IDs that appear exactly once in the database.

Key Observation:

A non-repeating element is an element whose frequency is exactly 1.

The most efficient solution is:

1. Count frequencies using a HashMap.
2. Traverse the original array.
3. Print elements having frequency = 1.

This preserves the original order.
*/

/*
Brute Force:    TC -> O(N^2)    SC -> O(1)

Algorithm:
1. For every element, count its occurrences in the array.
2. If count equals 1, print the element.
*/

// #include <iostream>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;

//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     bool found = false;

//     for (int i = 0; i < n; i++)
//     {
//         int count = 0;

//         for (int j = 0; j < n; j++)
//         {
//             if (arr[i] == arr[j])
//             {
//                 count++;
//             }
//         }

//         if (count == 1)
//         {
//             cout << arr[i] << " ";
//             found = true;
//         }
//     }

//     if (!found)
//     {
//         cout << "No Non-Repeating Elements";
//     }

//     return 0;
// }

/*
Better:     TC -> O(N log N)      SC -> O(1)

Algorithm:
1. Sort the array.
2. Check neighboring elements.
3. Elements appearing exactly once are non-repeating.
*/

// #include <iostream>
// #include <algorithm>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;

//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     sort(arr, arr + n);

//     bool found = false;

//     for (int i = 0; i < n; i++)
//     {
//         if ((i == 0 || arr[i - 1] != arr[i]) && (i == n - 1 || arr[i] != arr[i + 1]))
//         {
//             cout << arr[i] << " ";
//             found = true;
//         }
//     }

//     if (!found)
//     {
//         cout << "No Non-Repeating Elements";
//     }

//     return 0;
// }

/*
Optimal:    TC -> O(N)      SC -> O(N)

Algorithm:
1. Create an unordered_map<int, int> freq.
2. Count the frequency of each element.
3. Traverse the original array.
4. Print elements whose frequency is exactly 1.
*/

#include <iostream>
#include <unordered_map>
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

    bool found = false;

    for (int i = 0; i < n; i++)
    {
        if (freq[arr[i]] == 1)
        {
            cout << arr[i] << " ";
            found = true;
        }
    }

    if (!found)
    {
        cout << "No Non-Repeating Elements.";
    }

    return 0;
}