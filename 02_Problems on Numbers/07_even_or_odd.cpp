/*
Q32. Check Whether a Given Number is Even or Odd

Topic:  Numbers

Difficulty: Easy

Pattern:    Divisibility by 2

TCS Frequency:  Very High

Constraints:
-10^9 ≤ N ≤ 10^9
Input can be positive, negative, or zero

Input Format:

A single integer N.

Output Format:

Print:
    "Even" if the number is even
    "Odd" if the number is odd

Sample Input:   24
Sample Output:  Even

TCS Story Version:
A company assigns employee IDs. IDs divisible by 2 are processed by Server A, while the remaining IDs are processed by Server B.

Given an employee ID, determine which server will process it.

Mathematical Concept Used:

Even Number:    N % 2 == 0

Odd Number:     N % 2 != 0

Key Observation:

Every integer belongs to exactly one category:
Even → divisible by 2
Odd → not divisible by 2

Examples:
2, 4, 6, 8, 10 → Even
1, 3, 5, 7, 9 → Odd

*/

/*
Brute Force:        TC -> O(1)      SC -> O(1)

Algorithm:
1. Divide the number by 2.
2. Check remainder.
3. If remainder is 0 → Even.
4. Else → Odd.
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n % 2 == 0)
    {
        cout << "Even";
    }
    else
    {
        cout << "Odd";
    }

    return 0;
}

/*
Optimal:    TC -> O(1)      SC -> O(1)

Algorithm:
1. Use bitwise AND operation.
2. Check last binary bit.
3. If last bit is 0 → Even.
4. If last bit is 1 → Odd.
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if ((n & 1) == 0)
    {
        cout << "Even";
    }
    else
    {
        cout << "Odd";
    }

    return 0;
}