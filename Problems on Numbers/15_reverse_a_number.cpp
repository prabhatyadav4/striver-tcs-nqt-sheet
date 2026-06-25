/*
Q40. Reverse Digits of a Number

Topic:  Numbers

Difficulty: Easy

Pattern:    Digits Manipulation

TCS Frequency:  Very High

Constraints:
0 ≤ N ≤ 10^18
Use long long for large inputs

Input Format:   A single integer N.

Output Format:  Print the number obtained after reversing its digits.

Sample Input:
12345

Sample Output:
54321

TCS Story Version:

A company generates transaction IDs. For verification purposes, the system needs to display the ID in reverse order.

Given a transaction ID, reverse its digits and print the result.

Mathematical Concept Used:

Digit Extraction:   Last Digit = N % 10

Digit Removal:  N = N / 10

Reverse Formation:
reverse = reverse * 10 + digit

Key Observation:

The last digit of a number can be extracted using % 10.
By repeatedly extracting digits and appending them to a new number, we can construct the reverse.

Example:    1234
4 → 43 → 432 → 4321
*/

/*
Brute Force:        TC -> O(N)      SC -> O(N)

Algorithm:
1. Convert the number into a string.
2. Reverse the string.
3. Print the reversed string.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    string num = to_string(n);

    reverse(num.begin(), num.end());

    cout << num;

    return 0;
}

/*
Better:     TC -> O(N)      SC -> O(N);

Algorithm:
1. Extract digits using % 10.
2. Store digits in a vector.
3. Reconstruct the reversed number.
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> digits;

    while (n > 0)
    {
        digits.push_back(n % 10);
        n /= 10;
    }

    for (int digit : digits)
    {
        cout << digit;
    }

    return 0;
}

/*
Optimal:        TC -> O(N)      SC -> O(1)

Algorithm:
1. Initialize reverse = 0.
2. While N > 0:
    Extract last digit using % 10.
    Append digit to reverse.
    Remove last digit using / 10.
3. Print reverse.
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int reverseNum = 0;
    while (n > 0)
    {
        int digit = n % 10;
        reverseNum = reverseNum * 10 + digit;
        n /= 10;
    }

    cout << reverseNum;

    return 0;
}