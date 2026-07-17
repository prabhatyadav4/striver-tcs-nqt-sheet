/*
Q27. Find All Palindrome Numbers in a Given Range

Topic:  Numbers

Difficulty: Easy

Pattern:    Range Traversal + Palindrome Check

TCS Frequency:  High

Constraints:
1 ≤ L ≤ R ≤ 10^5 (typically in TCS)
Range may contain multiple palindrome numbers

Input Format:

Two integers:   L R

where:
    L = Starting number
    R = Ending number

Output Format:

Print all palindrome numbers present in the range separated by spaces.

Sample Input:
10 150

Sample Output:
11 22 33 44 55 66 77 88 99 101 111 121 131 141

TCS Story Version:

A company stores employee IDs from L to R.

A special employee ID is one that remains the same when read from left to right and right to left.

Find and display all special employee IDs within the given range.

Mathematical Concept Used:
    Number Reversal
    Digit Extraction using % 10
    Range Traversal

Key Observation:

A number is palindrome if:

    Number == Reverse(Number)

Therefore:

1. Traverse every number in the range.
2. Reverse it.
3. Compare with original.
4. Print if palindrome.
*/

/*
Brute Force:    TC -> O((R-L+1) × D)        SC -> O(D)

Algorithm:
1. Traverse from L to R.
2. Convert each number into string.
3. Reverse the string.
4. Compare original and reversed string.
5. If equal, print the number.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int L, R;
    cin >> L >> R;

    for (int i = L; i <= R; i++)
    {
        string s = to_string(i);
        string rev = s;

        reverse(s.begin(), s.end());

        if (s == rev)
        {
            cout << i << " ";
        }
    }

    return 0;
}

/*
Optimal:        TC -> O((R-L+1) × D)        SC -> O(1)

Algorithm:
1. Create a function to check palindrome using digit reversal.
2. Traverse from L to R.
3. For every number:
    Reverse digits.
    Compare with original.
4. Print all palindrome numbers.
*/

#include <iostream>
using namespace std;

int main()
{
    int L, R;
    cin >> L >> R;

    for (int num = L; num <= R; num++)
    {
        int original = num;
        int reversed = 0;
        int n = num;

        while (n > 0)
        {
            int digit = n % 10;
            reversed = reversed * 10 + digit;
            n /= 10;
        }

        if (original == reversed)
        {
            cout << original << " ";
        }
    }

    return 0;
}