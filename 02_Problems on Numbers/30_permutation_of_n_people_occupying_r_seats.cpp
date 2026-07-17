/*
Q55. Permutations in Which N People Can Occupy R Seats

Topic: Numbers / Recursion

Difficulty: Easy

Pattern: Permutation / Backtracking

Problem Statement:

You are given N distinct people and R distinct seats in a classroom.

Find the total number of ways in which R seats can be occupied by
choosing and arranging people from the N available people.

Each seat can contain only one person, and a person cannot occupy
more than one seat.

Since the seats are distinct, changing the order of people creates
a different arrangement.

If R is greater than N, print 0 because there are not enough people
to occupy all the seats.

Input Format:

The input contains two space-separated integers:

N R

Where:

N represents the total number of people.
R represents the total number of seats.

Output Format:

Print the total number of possible arrangements.

Constraints:

1 <= N <= 20
0 <= R <= 20

Sample Input 1:

5 3

Sample Output 1:

60

Explanation:

There are 5 choices for the first seat.

After selecting one person, there are 4 choices for the second seat.

After selecting two people, there are 3 choices for the third seat.

Total arrangements:

5 * 4 * 3 = 60

The permutation formula is:

NPR = N! / (N - R)!
*/

/*
Optimal Solution

Approach:

Instead of calculating complete factorials, directly multiply only
the required R factors.

Permutation formula:

NPR = N! / (N - R)!

After cancelling the common factorial terms:

NPR = N * (N - 1) * (N - 2) * ... for R factors

Example:

N = 5
R = 3

5P3 = 5 * 4 * 3
    = 60

Steps:

1. Initialize answer as 1.
2. Run a loop R times.
3. Multiply answer by N - i during each iteration.
4. Print the final answer.
5. If R is greater than N, print 0.

Time Complexity:    O(R)

Space Complexity:   O(1)
*/

#include <iostream>
using namespace std;

int main()
{
    int n, r;
    cin >> n >> r;

    if (r > n || r < 0)
    {
        cout << 0;
        return 0;
    }

    long long answer = 1;

    for (int i = 0; i < r; i++)
    {
        answer *= (n - i);
    }

    cout << answer;

    return 0;
}