/*
Greatest of Three Numbers

Topic:  Numbers

Difficulty: Easy

Pattern:    Multiple Number Comparison

TCS Frequency:  Very High

Constraints:
-10^18 ≤ A, B, C ≤ 10^18
Numbers can be positive, negative, or zero

Input Format:

Three integers: A B C

Output Format:

Print the greatest number among A, B, and C.

Sample Input:
10 25 15

Sample Output:
25

TCS Story Version:

A company evaluates the monthly sales of three employees.

Employee A achieved A sales.
Employee B achieved B sales.
Employee C achieved C sales.

Find the employee with the highest sales by determining the greatest value among the three.

Mathematical Concept Used:

Comparison Property:

If A ≥ B and A ≥ C → A is greatest

If B ≥ A and B ≥ C → B is greatest

Otherwise → C is greatest

Key Observation:
Among three numbers, only one comparison chain is needed:
A ≥ B and A ≥ C
B ≥ A and B ≥ C
Else C is greatest
*/

/*
Brute Force:        TC -> O(1)      SC -> O(1)

Algorithm:
1. Store all three numbers.
2. Compare each number with the others.
3. Print the largest number.
*/

// #include <iostream>
// using namespace std;

// int main()
// {
//     int a, b, c;
//     cin >> a >> b >> c;

//     if (a >= b && a >= c)
//     {
//         cout << a;
//     }
//     else if (b >= a && b >= c)
//     {
//         cout << b;
//     }
//     else
//     {
//         cout << c;
//     }

//     return 0;
// }

/*
Optimal:        TC -> O(1)      SC -> O(1)

Algorithm:
1.cUse nested max() function.
2. Compute maximum among three numbers.
3. Print the result.
*/

#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    cout << max(a, max(b, c));

    return 0;
}