/*
Q26. Check if a Number is Palindrome or Not

Topic:  Numbers

Difficulty: Easy

Pattern:    Reverse Number and Compare

TCS Frequency:  High

Constraints:
0 ≤ N ≤ 10^18 (depends on platform)
Number contains only digits

Input Format:
A single integer N.

Output Format:
Print:
    "Palindrome" if the number is a palindrome
    "Not Palindrome" otherwise

Sample Input:
121

Sample Output:
Palindrome

TCS Story Version:

A company generates unique employee IDs. An ID is considered special if it reads the same from left to right and right to left.

Given an employee ID number, determine whether it is a special ID or not.

Mathematical Concept Used:
    Reversing Digits of a Number
    Modulus Operator (%)
    Integer Division (/)

Key Observation:
A number is a palindrome if:    Original Number = Reversed Number

Example:    121 → Reverse = 121

Since both are equal, it is a palindrome.
*/

/*
Brute Force:    TC -> O(D)      SC -> O(D)  where D is No. of Digits

Algorithm:
1. Convert the number into a string.
2. Reverse the string.
3. Compare original and reversed strings.
4. If equal → Palindrome.
5. Else → Not Palindrome.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    string s = to_string(n);
    string rev = s;

    reverse(rev.begin(), rev.end());

    if (s == rev)
    {
        cout << "Palindrome";
    }
    else
    {
        cout << "Not Palindrome";
    }

    return 0;
}

/*
Optimal     TC -> O(D)      SC -> O(1)

Algorithm:
1. Save the original number.
2. Extract last digit using % 10.
3. Build reverse using:
    reverse = reverse * 10 + digit
4. Remove last digit using / 10.
5. Compare original and reversed numbers.
6. If equal → Palindrome.
*/

#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    long long original = n;
    long long reversed = 0;

    while (n > 0)
    {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }

    if (original == reversed)
    {
        cout << "Palindrome";
    }
    else
    {
        cout << "Not Palindrome";
    }

    return 0;
}