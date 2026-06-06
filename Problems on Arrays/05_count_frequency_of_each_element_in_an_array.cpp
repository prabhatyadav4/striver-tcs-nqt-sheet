/*
Q5. Count Frequency of Each Element in an Array

Topic: Arrays

Difficulty: Easy-Medium

Pattern: Hashing / Frequency Count

Constraints:
1 ≤ N ≤ 10^5
-10^9 ≤ arr[i] ≤ 10^9

Input Format:
First line contains integer N.
Second line contains N space-separated integers.

Output Format:
For each distinct element, print the element and its frequency.

Sample Input:
7
10 5 10 15 10 5 20

Sample Output:
10 3
5 2
15 1
20 1

TCS Story Version:
A supermarket records the product IDs of items sold during a day.
The manager wants to know how many times each product was sold. Given the list of product IDs, find the frequency of every distinct product.

Key Observation:
To count frequencies efficiently, we need to remember how many times each element has appeared. A hash map (unordered_map) allows insertion and lookup in nearly constant time, making it the optimal choice.

*/

/*
Brute Force: TC -> O(N^2)   SC -> O(N)

Algorithm:
1. Traverse each element.
2. For every element, count its occurrences by scanning the entire array.
3. Use a visited array to avoid printing duplicates.
4. Print element and its count.

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

        cout << arr[i] << " " << count << endl;
    }

    return 0;
}

/*
Better: TC -> O(N log N)    SC -> O(1)

Algorithm:
1. Sort the array.
2. Traverse the sorted array.
3. Count consecutive equal elements.
4. Print element and its frequency.

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

    int count = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] == arr[i])
        {
            count++;
        }
        else
        {
            cout << arr[i - 1] << " " << count << endl;
            count = 1;
        }
    }

    cout << arr[n - 1] << " " << count << endl;

    return 0;
}

/*
Optimal: TC -> O(N)     SC -> O(N)

Algorithm:
1. Create an unordered_map<int, int>.
2. Traverse the array and increment the count of each element.
3. Traverse the hash map.
4. Print each element with its frequency.

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

    for (auto it : freq)
    {
        cout << it.first << " " << it.second << endl;
    }

    return 0;
}