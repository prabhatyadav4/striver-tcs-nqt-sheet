/*
TCS NQT March 2026 - Gym Membership Plan
--------------------

Description:
    A gym offers membership plans for fixed durations (in months). Given an integer N
    representing the desired number of months, determine the cost of the corresponding
    membership plan. If no plan exists for the given duration, output "Error".

Available Plans:
    1 month   -> 2000
    3 months  -> 5000
    6 months  -> 8000
    9 months  -> 11000
 12 months  -> 12000

Input:
    A single integer N (1 <= N <= 12) — the desired membership duration in months.

Output:
    If a plan exists for N months, print its cost (as an integer). Otherwise, print
    the word: Error

Examples:
    Input:  6
    Output: 8000

    Input:  2
    Output: Error

*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    switch (n)
    {
    case 1:
        cout << 2000;
        break;
    case 3:
        cout << 5000;
        break;
    case 6:
        cout << 8000;
        break;
    case 9:
        cout << 11000;
        break;
    case 12:
        cout << 12000;
        break;
    default:
        cout << "Error";
    }

    return 0;
}