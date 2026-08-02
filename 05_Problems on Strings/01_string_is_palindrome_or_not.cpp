/*
Q73. Check if a Given String is Palindrome or Not

Topic:  Strings

Difficulty: Easy

Pattern:    Two Pointers / String Traversal

TCS Frequency:  High

Constraints:
1 ≤ Length of String ≤ 10^5

Input Format:
One string:    S

Output Format:
Print:
Palindrome

or

Not a Palindrome

Sample Input:
madam

Sample Output:
Palindrome

Sample Input:
level

Sample Output:
Palindrome

Sample Input:
hello

Sample Output:
Not a Palindrome

Explanation:

A palindrome is a string that reads the same
from left to right and right to left.

Examples:

madam
↓

madam

Same in both directions.

TCS Story Version:

A company generates unique product IDs.

An ID is considered valid only if it reads the
same from both directions.

Given a string S, determine whether it is a
Palindrome.

Mathematical Concept Used:

Palindrome

A string is called a palindrome if

Original String == Reverse String

Examples:

madam

racecar

level

refer

Key Observation

To determine whether a string is a palindrome,
we only need to compare the first character
with the last, the second with the second-last,
and so on.

There is no need to reverse the entire string.
*/

/*
Brute Force:        TC -> O(N)      SC -> O(N)

Algorithm:
1. Read the string.
2. Create another string by reversing it.
3. Compare the reversed string with the original.
4. If both are equal,
   print Palindrome.
5. Otherwise print Not a Palindrome.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;

    string rev = s;

    reverse(rev.begin(), rev.end());

    if (s == rev)
    {
        cout << "Palindrome";
    }
    else
    {
        cout << "Not a Palindrome";
    }

    return 0;
}

/*
Better:     TC -> O(N)      SC -> O(1)

Algorithm:
1. Read the string.
2. Initialize two pointers:
   left = 0
   right = last index.
3. Compare both characters.
4. If they differ,
   print Not a Palindrome.
5. Otherwise move both pointers inward.
6. If all characters match,
   print Palindrome.
*/

#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int left = 0;
    int right = s.length() - 1;

    while (left < right)
    {
        if (s[left] != s[right])
        {
            cout << "Not a Palindrome";
            return 0;
        }

        left++;
        right--;
    }

    cout << "Palindrome";

    return 0;
}

/*
Optimal:        TC -> O(N)      SC -> O(1)

Algorithm:
1. Read the string.
2. Traverse only till the middle.
3. Compare
   s[i] with s[n-i-1].
4. If any pair differs,
   print Not a Palindrome.
5. Otherwise print Palindrome.
*/

#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int n = s.length();

    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - i - 1])
        {
            cout << "Not a palindrome";
            return 0;
        }
    }

    cout << "Palindrome";
    return 0;
}