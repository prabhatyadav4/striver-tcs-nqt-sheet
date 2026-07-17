/*
Q16. Find All Symmetric Pairs in an Array

Topic:  Arrays

Difficulty: Medium

Pattern:    Hashing / Pair Mapping

Constraints:
1 ≤ N ≤ 10^5
Each element is represented as a pair (x, y)

Input Format:
First line contains integer N (number of pairs).
Next N lines contain two integers x and y.

Output Format:

Print all symmetric pairs.

A pair (a, b) is symmetric to (b, a).

Sample Input:
5
1 2
3 4
5 9
4 3
2 1

Sample Output:
4 3
2 1

TCS Story Version:

A communication network stores connections between devices as ordered pairs (A, B). A connection is considered symmetric if there exists another connection (B, A). Find all such symmetric connections.

Key Observation:

For a pair: (a, b)

we need to check whether:   (b, a)  already exists.

Hashing allows us to perform this lookup in O(1).
*/

/*
Brute Force:    TC -> O(N^2)    SC -> O(1)

Algorithm:
1. For every pair (a,b).
2. Search the remaining pairs for (b,a).
3. If found, print the pair.
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n][2];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i][0] == arr[j][1] && arr[i][1] == arr[j][0])
            {
                cout << "(" << arr[i][0] << " " << arr[i][1] << ")" << endl;
            }
        }
    }

    return 0;
}

/*
Optimal:    TC -> O(N)      SC -> O(N)

Algorithm:
1. Use a set of pairs
2. For every pair (a,b):
    Check whether (b,a) already exists.
    If yes → symmetric pair found.
    Otherwise store (a,b).
*/

#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;
    cin >> n;

    set<pair<int, int>> st;

    bool found = false;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        if (st.find({b, a}) != st.end())
        {
            cout << "(" << b << "," << a << ")" << endl;
            found = true;
        }
        else
        {
            st.insert({a, b});
        }
    }

    if (!found)
    {
        cout << "No Symmetric Pair";
    }

    return 0;
}