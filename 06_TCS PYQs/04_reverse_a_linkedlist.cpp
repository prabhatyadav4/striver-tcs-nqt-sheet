/*
Reverse a Linked List (Iterative)

Problem (TCS-style framing)
A playlist is stored as a singly linked list of song IDs. Reverse the order of the playlist so the last song plays first.

Example
Input: 1 -> 2 -> 3 -> 4 -> NULL
Output: 4 -> 3 -> 2 -> 1 -> NULL

Brute Force Approach
Push all node values onto a stack (or into an array), then rebuild the list in reverse order. Uses O(N) extra space.

Optimal Approach
Reverse the links in place using three pointers: prev, curr, next. Single pass, O(1) extra space.
*/

#include <iostream>
using namespace std;

struct Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        this->data = val;
        this->next = nullptr;
    }
};

Node *reverseList(Node *head)
{
    Node *prev = nullptr;
    Node *curr = head;

    while (curr != nullptr)
    {
        Node *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    head = reverseList(head);

    printList(head);

    return 0;
}