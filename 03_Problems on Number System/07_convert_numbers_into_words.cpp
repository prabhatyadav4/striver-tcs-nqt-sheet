/*
Q67. Convert a Number into Words

Topic: Numbers / Strings

Difficulty: Medium

Pattern: Place Value Decomposition

Problem Statement:

You are given a non-negative integer N.

Convert the number into its complete English word representation.

The number may contain billions, millions, thousands and hundreds.

Input Format:

The input contains one non-negative integer N.

Output Format:

Print the English word representation of N.

Constraints:

0 <= N <= 10^12

Sample Input 1:

12345

Sample Output 1:

Twelve Thousand Three Hundred Forty Five

Sample Input 2:

1000001

Sample Output 2:

One Million One

Sample Input 3:

0

Sample Output 3:

Zero

Approach:

1. Divide the number into groups of three digits.
2. Convert each group into words.
3. Attach its place-value name:
   - Billion
   - Million
   - Thousand
4. Join all non-zero groups.

Time Complexity:    O(log N)

Space Complexity:   O(log N)
*/

#include <iostream>
#include <string>
using namespace std;

string convertBelowThousand(int number)
{
    string belowTwenty[] = {
        "", "One", "Two", "Three", "Four",
        "Five", "Six", "Seven", "Eight", "Nine",
        "Ten", "Eleven", "Twelve", "Thirteen",
        "Fourteen", "Fifteen", "Sixteen",
        "Seventeen", "Eighteen", "Nineteen"};

    string tens[] = {
        "", "", "Twenty", "Thirty", "Forty",
        "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    string result = "";

    if (number >= 100)
    {
        result += belowTwenty[number / 100] + " Hundred";
        number %= 100;

        if (number != 0)
        {
            result += " ";
        }
    }

    if (number >= 20)
    {
        result += tens[number / 10];
        number %= 10;

        if (number != 0)
        {
            result += " " + belowTwenty[number];
        }
    }

    else if (number > 0)
    {
        result += belowTwenty[number];
    }

    return result;
}

int main()
{
    long long number;
    cin >> number;

    if (number < 0)
    {
        cout << "Invalid Input";
        return 0;
    }

    if (number == 0)
    {
        cout << "Zero";
        return 0;
    }

    string result;

    long long billionPart = number / 1000000000;
    number %= 1000000000;

    long long millionPart = number / 1000000;
    number %= 1000000;
    ;

    long long thousandPart = number / 1000;
    number %= 1000;

    int remainingPart = number;

    if (billionPart != 0)
    {
        result += convertBelowThousand(billionPart) + " Billion";
    }

    if (millionPart != 0)
    {
        if (!result.empty())
        {
            result += " ";
        }

        result += convertBelowThousand(millionPart) + " Million";
    }

    if (thousandPart != 0)
    {
        if (!result.empty())
        {
            result += " ";
        }

        result += convertBelowThousand(thousandPart) + " Thousand";
    }

    if (remainingPart != 0)
    {
        if (!result.empty())
        {
            result += " ";
        }

        result += convertBelowThousand(remainingPart);
    }

    cout << result;

    return 0;
}