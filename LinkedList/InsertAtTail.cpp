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
    head->val = 100;
    head->next = NULL;

    Node *second = new Node();
    second->val = 200;
    second->next = NULL;
    head->next = second;

    Node *third = new Node();
    third->val = 300;
    third->next = NULL;
    second->next = third;

    Node *insert = new Node();
    insert->val = 400;
    insert->next = NULL;

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = insert;

    Node* ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->val << " -> ";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;

    return 0;
}