#include <iostream>

using namespace std;

struct Node
{

    int val;
    Node *next;
};
Node *Reverse(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;

    while (curr != NULL)
    {
        Node *nextnode = curr->next;

        curr->next = prev;

        prev = curr;

        curr = nextnode;
    }
    return prev;
}
int main()
{

    Node *head = new Node();
    head->val = 1;
    head->next = NULL;

    Node *second = new Node();
    second->val = 2;
    second->next = NULL;
    head->next = second;

    Node *third = new Node();
    third->val = 3;
    third->next = NULL;
    second->next = third;

    head = Reverse(head);

    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL";

    return 0;
}