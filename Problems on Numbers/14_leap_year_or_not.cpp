/*
Q39. Check Whether a Year is Leap Year or Not

Topic:  Numbers

Difficulty: Easy

Pattern:    Mathematical Logic

TCS Frequency:  Very High

Constraints:
1 ≤ Year ≤ 10^9

Input Format:

A single integer representing the year.

Output Format:

Print:
"Leap Year" if the year is a leap year
"Not Leap Year" otherwise

Sample Input:   2024

Sample Output:  Leap Year

TCS Story Version:

A company stores employee attendance records based on calendar years. To correctly calculate the number of days in February, the system must determine whether a given year is a Leap Year.

Given a year, determine whether it is a Leap Year or not.

Mathematical Concept Used:

A year is a Leap Year if:
(Year % 400 == 0)
OR
(Year % 4 == 0 AND Year % 100 != 0)

Examples:
2000 → Leap Year
2024 → Leap Year
1900 → Not Leap Year
2023 → Not Leap Year

Key Observation:

The leap year rule consists of three conditions:
    Divisible by 400 → Leap Year
    Divisible by 100 but not 400 → Not Leap Year
    Divisible by 4 but not 100 → Leap Year
*/

/*
Brute Force:        TC -> O(1)      SC -> O(1)

Algorithm:
1. Check divisibility by 400.
2. If divisible, Leap Year.
3. Otherwise check divisibility by 100.
4. If divisible, Not Leap Year.
5. Otherwise check divisibility by 4.
6. If divisible, Leap Year.
7. Else Not Leap Year.
*/

// #include <iostream>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;

//     if (n % 400 == 0)
//     {
//         cout << "Leap Year";
//     }
//     else if (n % 100 == 0)
//     {
//         cout << "Not Leap Year";
//     }
//     else if (n % 4 == 0)
//     {
//         cout << "Leap Year";
//     }
//     else
//     {
//         cout << "Not Leap Year";
//     }

//     return 0;
// }

/*
Optimal:        TC -> O(1)      SC -> O(1)

Algorithm:
1. Read the year.
2. Apply the leap year formula:
    (year % 400 == 0) ||
    (year % 4 == 0 && year % 100 != 0)
3. Print the result.
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if ((n % 400 == 0) || (n % 4 == 0 && n % 100 != 0))
    {
        cout << "Leap Year";
    }
    else
    {
        cout << "Not Leap Year";
    }

    return 0;
}