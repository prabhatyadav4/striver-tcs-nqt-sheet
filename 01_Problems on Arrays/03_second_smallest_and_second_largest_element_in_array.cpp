/*
Q3. Second Smallest and Second Largest Element in an Array

Topic: Arrays

Difficulty: Easy-Medium

Pattern:    Minimum / Maximum / Array Traversal

Constraints:
2 ≤ N ≤ 10^5
-10^9 ≤ arr[i] ≤ 10^9

Input Format:
First line contains integer N.
Second line contains N space-separated integers.

Output Format:
Print the second smallest and second largest element.

Sample Input:
6
1 2 4 7 7 5

Sample Output:
2 5

TCS Story Version:

A company stores the salaries of its employees.
The HR manager wants to identify the employee with the second lowest salary and the employee with the second highest salary for special review.
Find both values.

Key Observation:
Sorting works, but costs O(N log N).
We can find both values in a single traversal.
Duplicates should not be considered as second smallest/largest.
*/

/*
Brute Force: TC -> O(N log N)   SC -> O(1)

Algorithm:

1. Sort the array.
2. Traverse from the beginning to find the first element different from the smallest.
3. Traverse from the end to find the first element different from the largest.
4. Print both values.
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

//     if (n < 2)
//     {
//         cout << "-1 -1";
//         return 0;
//     }

//     sort(arr, arr + n);

//     int secondSmall = -1;
//     int secondLarge = -1;

//     for (int i = 1; i < n; i++)
//     {
//         if (arr[i] != arr[i - 1])
//         {
//             secondSmall = arr[i];
//             break;
//         }
//     }

//     for (int i = n - 2; i >= 0; i--)
//     {
//         if (arr[i] != arr[n - 1])
//         {
//             secondLarge = arr[i];
//             break;
//         }
//     }

//     cout << secondSmall << " " << secondLarge;

//     return 0;
// }

/*
Optimal: TC -> O(N)     SC -> O(1)

Algorithm:

We will need four variables: small, second_small, large, and second_large. Initialize small and second_small to INT_MAX, and large and second_large to INT_MIN.

Second Smallest Algorithm:
    If the current element is smaller than 'small', update the values of second_small and small.
    Else if the current element is smaller than 'second_small', update the value of second_small.
    After traversing the array, the second smallest element will be stored in the variable second_small.

Second Largest Algorithm:
    If the current element is larger than 'large', update the values of second_large and large.
    Else if the current element is larger than 'second_large', update the value of second_large.
    After traversing the array, the second largest element will be stored in the variable second_large.
*/

#include <iostream>
#include <climits>
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

    if (n < 2)
    {
        cout << "-1 -1";
        return 0;
    }

    int smallest = INT_MAX;
    int largest = INT_MIN;
    int secondSmall = INT_MAX;
    int secondLarge = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            secondSmall = smallest;
            smallest = arr[i];
        }
        else if (arr[i] > smallest && arr[i] < secondSmall)
        {
            secondSmall = arr[i];
        }

        if (arr[i] > largest)
        {
            secondLarge = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > secondLarge)
        {
            secondLarge = arr[i];
        }
    }

    cout << secondSmall << " " << secondLarge;

    return 0;
}