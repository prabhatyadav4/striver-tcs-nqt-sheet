/*
Q33. Check Whether a Number is Positive or Negative

Topic:  Numbers

Difficulty: Easy

Pattern:    Number Classification

TCS Frequency:  Very High

Constraints:
-10^18 ≤ N ≤ 10^18
Input can be positive, negative, or zero

Input Format:
A single integer N.

Output Format:
Print:
    "Positive" if N > 0
    "Negative" if N < 0
    "Zero" if N = 0

Sample Input:   25
Sample Output:  Positive

TCS Story Version:

A company tracks profit and loss values daily.

Positive value → Profit
Negative value → Loss
Zero → No Profit No Loss

Given a day's value, determine its category.

Mathematical Concept Used:

Number Sign Property:
N > 0  → Positive
N < 0  → Negative
N = 0  → Zero

Key Observation:

Every real integer belongs to exactly one of the following categories:
Positive
Negative
Zero
Therefore, simple comparison with zero is sufficient.
*/

/*
Brute Force:        TC -> O(1)      SC -> O(1)

Algorithm:
1. Read number N.
2. Compare N with 0.
3. If N > 0 → Positive.
4. If N < 0 → Negative.
5. Otherwise → Zero.
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n > 0)
    {
        cout << "Positive";
    }
    else if (n < 0)
    {
        cout << "Negative";
    }
    else
    {
        cout << "Zero";
    }

    return 0;
}

/*
Bit Manipulation Approach:      TC -> O(1)      SC -> O(1)

Algorithm:
1. Read the number n.
2. Right shift it by 31 bits.
3. Check the result:
    0 → Positive (or Zero)
    -1 → Negative
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n == 0)
    {
        cout << "Zero";
    }
    else if ((n >> 31) == 0)
    {
        cout << "Positive";
    }
    else
    {
        cout << "Negative";
    }

    return 0;
}