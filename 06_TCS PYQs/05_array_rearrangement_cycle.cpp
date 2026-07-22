/*
TCS NQT Coding 20 July 2026 Shift 2 (My Shift)

Q1. Array Rearrangement Cycle

Topic: Arrays

Difficulty: Easy

Pattern: Simulation / Perfect Shuffle

Problem Statement:

You are given an array of even size N.

In one operation, divide the array into two equal halves. Construct a
new array by taking one element from the second half, followed by one
element from the first half.

For example:

Original array:
1 2 3 4 | 5 6 7 8

After one operation:
5 1 6 2 7 3 8 4

Apply this operation repeatedly and find the minimum number of
operations required for the array to return to its original arrangement.

Input Format:

The first line contains an integer N.

The second line contains N space-separated distinct integers.

Output Format:

Print the minimum number of operations required to restore the
original arrangement.

Constraints:

2 <= N <= 10^5
N is even
1 <= arr[i] <= 10^9
All elements are distinct.

Sample Input:

8
1 2 3 4 5 6 7 8

Sample Output:

6

Approach:

1. Create an index array:

   0 1 2 ... N - 1

2. Apply the same rearrangement to the indices.

3. Continue until the index arrangement becomes the original order.

The actual values are not required because the operation depends only
on positions.

Time Complexity:    O(K * N)

Space Complexity:   O(N)
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> rearrangeIndices(const vector<int> &indices)
{
    int n = indices.size();
    int middle = n / 2;

    vector<int> result(n);

    for (int i = 0; i < middle; i++)
    {
        result[2 * i] = indices[middle + i];
        result[2 * i + 1] = indices[i];
    }

    return result;
}

int main()
{
    int n;
    cin >> n;

    vector<long long> arr(n);

    for (long long &value : arr)
    {
        cin >> value;
    }

    if (n % 2 != 0)
    {
        cout << "Invalid Input";
        return 0;
    }

    vector<int> current(n);
    vector<int> original(n);

    for (int i = 0; i < n; i++)
    {
        current[i] = i;
        original[i] = i;
    }

    long long operations = 0;

    do
    {
        current = rearrangeIndices(current);
        operations++;
    } while (current != original);

    cout << operations;

    return 0;
}