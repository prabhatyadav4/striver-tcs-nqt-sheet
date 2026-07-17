/*
Q57. Replace All 0s with 1s in a Given Integer

Topic: Numbers

Difficulty: Easy

Pattern: Digit Manipulation

TCS Frequency: High

Problem Statement:

You are given a non-negative integer N.

Replace every occurrence of digit 0 in N with digit 1 and print the
resulting number.

Input Format:

The input contains one non-negative integer N.

Output Format:

Print the number obtained after replacing every digit 0 with 1.

Constraints:

0 <= N <= 10^18

Sample Input 1:

1020

Sample Output 1:

1121

Explanation:

The digits 0 in 1020 are replaced with 1.

1020 -> 1121

Sample Input 2:

5006

Sample Output 2:

5116

Sample Input 3:

0

Sample Output 3:

1

Explanation:

The number contains a single digit 0, so it is replaced with 1.
*/

/*
Brute Solution:

Approach: String Conversion

1. Convert the integer into a string.
2. Traverse every character of the string.
3. Replace each character '0' with '1'.
4. Convert the modified string back into an integer.

Example:

Input:
1020

String:
"1020"

After replacement:
"1121"

Output:
1121

Time Complexity: O(D)

Space Complexity: O(D)

Where D is the number of digits in N.
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    string number = to_string(n);

    for (int i = 0; i < number.length(); i++)
    {
        if (number[i] == '0')
        {
            number[i] = '1';
        }
    }

    cout << stoi(number);

    return 0;
}

/*
Optimal Solution:

Approach:

1. Handle N = 0 separately because its answer is 1.
2. Extract every digit using N % 10.
3. If the extracted digit is 0, replace it with 1.
4. Reconstruct the number at the same place value.
5. Continue until all digits are processed.

Time Complexity:    O(log N)

Space Complexity:   O(1)
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n == 0)
    {
        cout << 1;
        return 0;
    }

    int result = 0;
    int placeValue = 1;

    while (n > 0)
    {
        int digit = n % 10;

        if (digit == 0)
        {
            digit = 1;
        }

        result += digit * placeValue;

        placeValue *= 10;
        n /= 10;
    }

    cout << result;

    return 0;
}