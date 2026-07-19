/*
TCS NQT March 2026 — Fraud Transaction Detection

Topic: Arrays / Structures

Difficulty: Easy

Pattern: Pair Comparison / Simulation

TCS Frequency: Moderate

Problem Statement:

A financial organization stores details of N transactions. Each transaction contains:
Sender name
Receiver name
Transaction time
Transaction amount

The transaction time is represented as a decimal numerical value.

Two transactions are considered fraudulent if all the following conditions are satisfied:
Both transactions have the same sender.
Both transactions have the same receiver.
Both transactions have the same transaction amount.
The absolute difference between their transaction times is less than or equal to 1.0.

Every transaction that belongs to at least one fraudulent pair must be printed.

Print the fraudulent transactions in the same order in which they were given in the input.

If no fraudulent transaction is found, print nothing.

Constraints:

1 ≤ N ≤ 1000

1 ≤ length of sender name ≤ 50

1 ≤ length of receiver name ≤ 50

0.0 ≤ transaction time ≤ 10^9

1 ≤ transaction amount ≤ 10^9

Sender and receiver names do not contain spaces.

Input Format:

The first line contains an integer N, representing the number of transactions.

The next N lines contain four space-separated values:

sender receiver time amount

Output Format:

Print every fraudulent transaction in the following format:

sender receiver time amount

The transactions must be printed in their original input order.

Sample Input 1:

5
A B 10.5 500
A B 10.4 500
A C 11.0 300
A B 12.3 500
D E 15.0 100

Sample Output 1:

A B 10.5 500
A B 10.4 500

Explanation:

The first and second transactions have:

The same sender: A
The same receiver: B
The same amount: 500

The absolute difference between their transaction times is:

|10.5 - 10.4| = 0.1

Since 0.1 is less than or equal to 1.0, both transactions are considered fraudulent.

The fourth transaction has the same sender, receiver and amount, but its time difference from the first and second transactions is greater than 1.0. Therefore, it is not fraudulent.

Sample Input 2:

4
Ram Shyam 20.5 1000
Ram Shyam 21.5 1000
Ram Mohan 20.8 1000
Ram Shyam 25.0 1000

Sample Output 2:

Ram Shyam 20.5 1000
Ram Shyam 21.5 1000

Explanation:

The first and second transactions satisfy all the required conditions.

Their time difference is:

|21.5 - 20.5| = 1.0

Since the difference is exactly 1.0, both transactions are fraudulent.

*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

struct Transaction
{
    string sender;
    string receiver;
    double time;
    int amount;
};

int main()
{
    int n;
    cin >> n;

    vector<Transaction> transactions(n);
    vector<bool> fraud(n, false);

    for (int i = 0; i < n; i++)
    {
        cin >> transactions[i].sender >> transactions[i].receiver >> transactions[i].time >> transactions[i].amount;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            bool sameSender =
                transactions[i].sender == transactions[j].sender;

            bool sameReceiver =
                transactions[i].receiver == transactions[j].receiver;

            bool sameAmount =
                transactions[i].amount == transactions[j].amount;

            bool withinOneTimeUnit =
                abs(transactions[j].time - transactions[i].time) <= 1.0;

            if (sameSender &&
                sameReceiver &&
                sameAmount &&
                withinOneTimeUnit)
            {
                fraud[i] = true;
                fraud[j] = true;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (fraud[i])
        {
            cout << transactions[i].sender << " "
                 << transactions[i].receiver << " "
                 << transactions[i].time << " "
                 << transactions[i].amount << '\n';
        }
    }

    return 0;
}