/*
Q. Sort Pairs Using a Custom Comparator

Topic: Sorting

Difficulty: Easy

Pattern: Custom Comparator

Problem Statement:

You are given N pairs of integers.

Sort the pairs according to the following rules:

1. Sort the pairs by their first element in ascending order.
2. If two pairs have the same first element, sort them by their
   second element in ascending order.

Use a custom comparator function for sorting.

Input Format:

The first line contains an integer N, representing the number of pairs.

The next N lines contain two integers, representing the first and
second elements of each pair.

Output Format:

Print the sorted pairs.

Each pair should be printed in the following format:

first second

Separate consecutive pairs using ", ".

Constraints:

1 <= N <= 10^5

-10^9 <= first, second <= 10^9

Sample Input:

3
3 6
2 4
7 8

Sample Output:

2 4, 3 6, 7 8

Explanation:

The pairs are sorted according to their first elements:

2 4
3 6
7 8

Sample Input 2:

5
3 8
2 5
3 4
1 9
2 1

Sample Output 2:

1 9, 2 1, 2 5, 3 4, 3 8

Explanation:

Pairs with the same first element are sorted according to their
second elements.

For first element 2:

2 1 comes before 2 5.

For first element 3:

3 4 comes before 3 8.

Approach:

1. Store all pairs in a vector.
2. Create a custom comparator function.
3. If the first elements are different, compare the first elements.
4. Otherwise, compare the second elements.
5. Use the sort() function with the custom comparator.
6. Print the sorted pairs.

Time Complexity:

Sorting N pairs takes O(N log N) time.

Space Complexity:

O(N) space is used to store the pairs.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool customComparator(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first != b.first)
    {
        return a.first < b.first;
    }

    return a.second < b.second;
}

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> pairs(n);

    for (int i = 0; i < n; i++)
    {
        cin >> pairs[i].first >> pairs[i].second;
    }

    sort(pairs.begin(), pairs.end(), customComparator);

    for (int i = 0; i < n; i++)
    {
        cout << pairs[i].first << " " << pairs[i].second;

        if (i != n - 1)
        {
            cout << ", ";
        }
    }

    return 0;
}