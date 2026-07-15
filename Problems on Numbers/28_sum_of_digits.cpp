/*
Q53. Repeatedly Find the Sum of Digits Until a Single Digit Remains

Topic: Numbers

Difficulty: Easy

Pattern: Digit Sum / Digital Root

Problem Statement:

Given a non-negative integer num, repeatedly calculate the sum of its
digits until the result contains only one digit.

Return or print the final single-digit result.

Input Format:

The input contains one non-negative integer num.

Output Format:

Print the single-digit result obtained after repeatedly adding
the digits of num.

Constraints:

0 <= num <= 10^18

Sample Input 1:

38

Sample Output 1:

2

Explanation:

First digit sum:

3 + 8 = 11

Since 11 contains more than one digit, find its digit sum again:

1 + 1 = 2

Therefore, the final result is 2.

Sample Input 2:

1234

Sample Output 2:

1

Explanation:

1 + 2 + 3 + 4 = 10

1 + 0 = 1

Therefore, the final result is 1.

Sample Input 3:

0

Sample Output 3:

0

Approach:

1. Continue while the number contains more than one digit.
2. Find the sum of all digits of the current number.
3. Replace the current number with the calculated digit sum.
4. Repeat until the number becomes a single digit.

Time Complexity:    O(log N) for practical input sizes.

Space Complexity:   O(1)
*/

#include <iostream>
using namespace std;

int main()
{
    long long num;
    cin >> num;

    while (num >= 10)
    {
        long long digitSum = 0;

        while (num > 0)
        {
            digitSum += num % 10;
            num /= 10;
        }

        num = digitSum;
    }

    cout << num;

    return 0;
}

/*
Optimal Approach: Digital Root Formula

For every positive integer:

Digital Root = 1 + (num - 1) % 9

For num = 0, the answer is 0.

Time Complexity: O(1)

Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    if (n == 0)
    {
        cout << 0;
    }
    else
    {
        cout << (1 + (n - 1) % 9);
    }

    return 0;
}