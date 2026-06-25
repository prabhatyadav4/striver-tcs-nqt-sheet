/*
Q41. Maximum and Minimum Digit in a Number

Topic:  Numbers

Difficulty: Easy

Pattern:    Digits Manipulation

TCS Frequency:  High

Constraints:
0 ≤ N ≤ 10^18
Use long long for large numbers

Input Format:   A single integer N.

Output Format:
Print:
Maximum Digit = X
Minimum Digit = Y

Sample Input:   583920
Sample Output:
Maximum Digit = 9
Minimum Digit = 0

TCS Story Version:

A company generates employee IDs consisting only of digits. For security analysis, the system needs to identify the highest and lowest digit present in an ID.

Given an employee ID, find the maximum and minimum digit present in the number.

Mathematical Concept Used:

Digit Extraction:   digit = N % 10

Digit Removal:  N = N / 10

Maximum Digit Update:   maxDigit = max(maxDigit, digit)

Minimum Digit Update:   minDigit = min(minDigit, digit)

Key Observation:
A number consists only of digits from:  0 to 9

By extracting every digit once, we can simultaneously track:
Largest digit encountered
Smallest digit encountered
*/

/*
Brute Force:       TC -> O(N)       SC -> O(D)

Algorithm:
1. Convert the number into a string.
2. Traverse each character.
3. Convert character into digit.
4. Update maximum and minimum digit.
5. Print the result.
*/

#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    string num = to_string(n);

    int minDigit = 9;
    int maxDigit = 0;

    for (char ch : num)
    {
        int digit = ch - '0';

        minDigit = min(minDigit, digit);
        maxDigit = max(maxDigit, digit);
    }

    cout << "Minimum Digit: " << minDigit << endl;
    cout << "Maximum Digit: " << maxDigit << endl;

    return 0;
}

/*
Better:     TC -> O(N)      SC -> O(N)

Algorithm:
1. Extract digits using % 10.
2. Store them in a vector.
3. Traverse the vector.
4. Find maximum and minimum digit.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    vector<int> digits;

    while (n > 0)
    {
        digits.push_back(n % 10);
        n /= 10;
    }

    int minDigit = *min_element(digits.begin(), digits.end());
    int maxDigit = *max_element(digits.begin(), digits.end());

    cout << "Minimum Digit: " << minDigit << endl;
    cout << "Maximum Digit: " << maxDigit << endl;

    return 0;
}

/*
Optimal:        TC -> O(D)      SC -> O(1)

Algorithm:
1. Initialize:
    maxDigit = 0
    minDigit = 9
2. Extract digits one by one using % 10.
3. Update maximum and minimum digit.
4. Remove the digit using / 10.
5. Continue until number becomes 0.
6. Print maximum and minimum digit.
*/

#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    if (n == 0)
    {
        cout << "Minimum Digit = 0" << endl;
        cout << "Maximum Digit = 0" << endl;
        return 0;
    }

    int minDigit = 9;
    int maxDigit = 1;

    while (n > 0)
    {
        int digit = n % 10;

        minDigit = min(minDigit, digit);
        maxDigit = max(maxDigit, digit);

        n /= 10;
    }

    cout << "Minimum Digit: " << minDigit << endl;
    cout << "Maximum Digit: " << maxDigit << endl;

    return 0;
}