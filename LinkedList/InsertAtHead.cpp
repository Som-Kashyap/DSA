#include <iostream>

using namespace std;

struct Node
{

    int val;
    Node *next;
};

int main()
{

    // create and link nodes:

    Node *head = new Node(); // created head
    head->val = 11;
    head->next = NULL;

    Node *second = new Node(); // second node
    second->val = 22;
    second->next = NULL;

    //  linking it with head :
    head->next = second;

    Node *third = new Node(); // third node
    third->val = 33;
    third->next = NULL;
    // linking it with second node:
    second->next = third;

    // Insert at head:
    Node *value = new Node();
    value -> val = 0;
    value -> next = head;
    head = value;

    Node *temp = head;
    // head -> next = second;

    while (temp != NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}