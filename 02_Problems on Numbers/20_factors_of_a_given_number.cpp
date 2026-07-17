/*
Q45. Factors of a Given Number

Topic:  Numbers

Difficulty: Easy

Pattern:    Factors / Divisors

TCS Frequency:  Very High

Constraints:
1 ≤ N ≤ 10^9
Use long long for larger inputs if required.

Input Format:

A single integer:   N

Output Format:

Print all the factors of the given number in increasing order.

Sample Input:
12

Sample Output:
1 2 3 4 6 12

TCS Story Version:

A company manufactures packets containing N items. To divide the items equally among different teams, the manager wants to know all possible team sizes that can divide the packets without leaving any remainder.

Given N, print all possible factors of the number.

Mathematical Concept Used:

A factor of N is any number that divides N completely.

If N % i == 0   then i is a factor.

Important Property:

Factors always occur in pairs.

If i divides N, then N/i is also a factor.

Example:    36
1 × 36
2 × 18
3 × 12
4 × 9
6 × 6

Key Observation:
Instead of checking every number from 1 to N, we only need to check till √N
because every factor greater than √N has a corresponding factor smaller than √N.
*/

/*
Brute Force         TC -> O(N)      SC -> O(1)

Algorithm:
1. Read N.
2. Traverse from 1 to N.
3. If N % i == 0
    Print i.
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
        }
    }

    return 0;
}

/*
Optimal:        TC -> O(sqrt(N))    SC -> O(sqrt(N))

Algorithm:
1. Read N.
2. Create two containers:
    First half of factors.
    Second half of factors.
3. Traverse from 1 to √N.
4. If i divides N:
    Print i immediately.
    Store N/i (if different).
5. Print stored factors in reverse order.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> factors;

    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            factors.push_back(i);
            if (i != n / i)
            {
                factors.push_back(n / i);
            }
        }
    }

    sort(factors.begin(), factors.end());

    for (int num : factors)
    {
        cout << num << " ";
    }

    return 0;
}