#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *next;
};

int main()
{

    Node *head = new Node();
    head->val = 10;
    head->next = NULL;

    Node *second = new Node();
    second->val = 20;
    second->next = NULL;
    head->next = second;

    Node *third = new Node();
    third->val = 30;
    third->next = NULL;
    second->next = third;

    Node* fourth = new Node();
    fourth->val = 40;
    fourth->next = NULL;

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL";

    return 0;
}
