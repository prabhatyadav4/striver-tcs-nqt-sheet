/*
Q37. Greatest of Two Numbers

Topic:  Numbers

Difficulty: Easy

Pattern:    Comparison of Numbers

TCS Frequency:  Very High

Constraints:
-10^18 ≤ A, B ≤ 10^18
Numbers can be positive, negative, or zero

Input Format:

Two integers:   A B
Output Format:
Print:
The greater number among A and B
If both numbers are equal, print "Both are Equal"

Sample Input:
10 25

Sample Output:
25

TCS Story Version:

A company compares the sales achieved by two employees.

Employee A achieved A sales.
Employee B achieved B sales.

Find which employee performed better by determining the greater sales value.

Mathematical Concept Used:

Comparison Property:

If A > B → A is greater
If B > A → B is greater
If A = B → Both are equal

Key Observation:
Only three possibilities exist:
A > B
A < B
A = B
A simple comparison is sufficient.
*/

/*
Brute Force:        TC -> O(1)      SC -> O(1)

Algorithm:
1. Read A and B.
2. Compare A and B.
3. Print the larger value.
4. If equal, print "Both are Equal".
*/

#include <iostream>
using namespace std;

int main()
{
    long long a, b;
    cin >> a >> b;

    if (a > b)
    {
        cout << a;
    }
    else if (a < b)
    {
        cout << b;
    }
    else
    {
        cout << "Both are Equal";
    }

    return 0;
}

/*
Optimal:    TC -> O(1)      SC -> O(1)

Algorithm:
1. Use the built-in max() function.
2. If numbers are equal, print "Both are Equal".
3. Otherwise print the maximum value.
*/

#include <iostream>
using namespace std;

int main()
{
    long long a, b;
    cin >> a >> b;

    if (a == b)
    {
        cout << "Both are Equal";
    }
    else
    {
        cout << max(a, b);
    }

    return 0;
}