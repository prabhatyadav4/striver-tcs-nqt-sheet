/*
Q59. Calculate the Area of a Circle

Topic: Basic Mathematics

Difficulty: Easy

Pattern: Formula-Based Problem

Problem Statement:

You are given the radius R of a circle.

Calculate and print the area of the circle.

The area of a circle is calculated using:

Area = PI * R * R

Use PI = 3.14159.

Input Format:

The input contains one floating-point number R, representing the radius
of the circle.

Output Format:

Print the area of the circle up to 2 digits after the decimal point.

Constraints:

0 <= R <= 10^6

Sample Input:

5

Sample Output:

78.54

Explanation:

Radius = 5

Area = 3.14159 * 5 * 5
     = 78.53975

After rounding to two decimal places:

78.54

Time Complexity:

O(1)

Space Complexity:

O(1)
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double radius;
    cin >> radius;

    const double PI = 3.14159;

    double area = PI * radius * radius;

    cout << fixed << setprecision(2) << area;

    return 0;
}