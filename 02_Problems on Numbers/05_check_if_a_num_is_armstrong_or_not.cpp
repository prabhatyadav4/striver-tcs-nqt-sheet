/*
Q30. Check if a Number is Armstrong Number or Not

Topic:  Numbers

Difficulty: Easy

Pattern:    Digit Extraction + Power Calculation

TCS Frequency:  Very High

Constraints:    0 ≤ N ≤ 10^9

Number may contain multiple digits

Input Format:

A single integer N.

Output Format:

Print:
"Armstrong" if the number is an Armstrong number
"Not Armstrong" otherwise

Sample Input: 153
Sample Output: Armstrong

TCS Story Version:

A company assigns special IDs to certain employees. An ID is considered special if the sum of each digit raised to the power of the total number of digits equals the original ID.

Given an employee ID, determine whether it is special or not.

Mathematical Concept Used:

For a number with D digits:

Armstrong Number:

(d1^D + d2^D + d3^D + ... + dn^D) = Number

Example:

153

Digits = 1, 5, 3
Number of digits = 3

1³ + 5³ + 3³
= 1 + 125 + 27
= 153

Hence Armstrong Number.

Key Observation:

To check Armstrong Number:
1. Count digits.
2. Extract every digit.
3. Raise digit to power (number of digits).
4. Add all powers.
5. Compare sum with original number.
*/

/*
Brute Force:        TC -> O(N)      SC -> O(N)

Algorithm:
1. Convert number into string.
2. Count digits using string length.
3. Traverse every character.
4. Convert character to digit.
5. Compute digit^digits.
6. Add all powers.
7. Compare with original number.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;

    string num = to_string(n);
    int digits = num.length();
    int sum = 0;
    int temp = n;

    while (temp > 0)
    {
        int digit = temp % 10;
        sum += pow(digit, digits);
        temp /= 10;
    }

    if (sum == n)
    {
        cout << "Armstrong";
    }
    else
    {
        cout << "Not Armstrong";
    }

    return 0;
}

/*
Optimal:    TC -> O(N)      SC -> O(1)

Algorithm:
1. Store original number.
2. Count total digits.
3. Extract each digit using % 10.
4. Add digit^digits to sum.
5. Compare sum with original number.
6. If equal → Armstrong.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int temp = n;
    int digits = 0;

    if (n == 0)
    {
        digits = 1;
    }
    else
    {
        while (temp > 0)
        {
            digits++;
            temp /= 10;
        }
    }

    temp = n;
    int sum = 0;

    while (temp > 0)
    {
        int digit = temp % 10;
        sum += pow(digit, digits);
        temp /= 10;
    }

    if (sum == n)
    {
        cout << "Armstrong";
    }
    else
    {
        cout << "Not Armstrong";
    }

    return 0;
}