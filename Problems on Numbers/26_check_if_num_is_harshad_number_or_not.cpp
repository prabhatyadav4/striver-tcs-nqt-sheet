/*
Q51. Check Whether the Given Number is a Harshad Number

Topic: Numbers

Difficulty: Easy

Pattern: Digit Sum / Divisibility

Problem Statement:

You are given a positive integer N.

A number is called a Harshad Number, or Niven Number, if it is
completely divisible by the sum of its digits.

Check whether the given number is a Harshad Number.

Input Format:

The input contains one positive integer N.

Output Format:

Print "Harshad Number" if N is divisible by the sum of its digits.

Otherwise, print "Not a Harshad Number".

Constraints:

1 <= N <= 10^9

Sample Input 1:

18

Sample Output 1:

Harshad Number

Explanation:

Sum of digits of 18:

1 + 8 = 9

18 is divisible by 9.

Therefore, 18 is a Harshad Number.

Sample Input 2:

19

Sample Output 2:

Not a Harshad Number

Explanation:

Sum of digits of 19:

1 + 9 = 10

19 is not divisible by 10.

Therefore, 19 is not a Harshad Number.

Approach:

1. Store the original number.
2. Find the sum of its digits.
3. Check whether the original number is divisible by the digit sum.
4. If divisible, print "Harshad Number".
5. Otherwise, print "Not a Harshad Number".

Time Complexity:    O(log N)

Space Complexity:   O(1)
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int originalNumber = n;
    int digitSum = 0;

    while (n > 0)
    {
        int digit = n % 10;
        digitSum += digit;
        n /= 10;
    }

    if (originalNumber % digitSum == 0)
    {
        cout << "Harshad Number";
    }
    else
    {
        cout << "Not a Harshad Number";
    }

    return 0;
}