/*
Q60. Find the Roots of a Quadratic Equation

Topic: Basic Mathematics

Difficulty: Easy

Pattern: Formula-Based Problem / Conditional Statements

Problem Statement:

You are given three coefficients A, B and C of a quadratic equation:

A*x^2 + B*x + C = 0

Find and print the roots of the quadratic equation.

The nature of the roots depends on the discriminant:

discriminant = B^2 - 4*A*C

1. If discriminant > 0:
   The equation has two distinct real roots.

2. If discriminant == 0:
   The equation has two equal real roots.

3. If discriminant < 0:
   The equation has two complex roots.

Input Format:

The input contains three space-separated numbers:

A B C

Output Format:

If the roots are real, print:

Root 1 = value
Root 2 = value

If the roots are complex, print them in the form:

Root 1 = realPart + imaginaryPart i
Root 2 = realPart - imaginaryPart i

Print all values up to two digits after the decimal point.

Constraints:

A != 0

Sample Input 1:

1 -5 6

Sample Output 1:

Root 1 = 3.00
Root 2 = 2.00

Explanation:

The equation is:

x^2 - 5x + 6 = 0

Discriminant:

D = (-5)^2 - 4*1*6
  = 25 - 24
  = 1

Since D > 0, the equation has two distinct real roots.

Sample Input 2:

1 -4 4

Sample Output 2:

Root 1 = 2.00
Root 2 = 2.00

Sample Input 3:

1 2 5

Sample Output 3:

Root 1 = -1.00 + 2.00i
Root 2 = -1.00 - 2.00i

Time Complexity:    O(1)

Space Complexity:   O(1)
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    double a, b, c;
    cin >> a >> b >> c;

    if (a == 0)
    {
        cout << "Not a Quadratic Equation";
        return 0;
    }

    double discriminant = b * b - 4 * a * c;

    cout << fixed << setprecision(2);

    if (discriminant > 0)
    {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "Root 1 = " << root1 << "\n";
        cout << "Root 2 = " << root2;
    }
    else if (discriminant == 0)
    {
        double root = -b / (2 * a);
        cout << "Root 1 = " << root << "\n";
        cout << "Root 2 = " << root;
    }
    else
    {
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * abs(a));

        cout << "Root 1 = " << realPart << " + " << imaginaryPart << "i\n";
        cout << "Root 2 = " << realPart << " - " << imaginaryPart << "i";
    }

    return 0;
}