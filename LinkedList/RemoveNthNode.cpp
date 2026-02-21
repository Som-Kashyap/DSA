#include <iostream>

using namespace std;

struct Node
{

    int val;
    Node *next;

};

Node *Remove(Node *head, int N)
{

    // Create dummy node for head rempval edge cases: Makes sure that for every node , there exists atleast one preceding node.
    Node *dummy = new Node();
    dummy->next = head;

    // Create two pointers initiating from dummy node:
    Node *slow = dummy;
    Node *fast = dummy;

    // Move fast N steps ahead iff N<=listlength :
    for (int i = 0; i < N; i++)
    {

        if (fast -> next == NULL) // N exceeds tail:
        {
            return head;
        }
        fast = fast->next;
    }
    // Move both pointers by same steps until fast reaches tail :
    while (fast != NULL)
    {

        slow = slow->next;
        fast = fast->next;
    }
    // Remove slow->next:
    slow->next = slow->next->next;

    // Return head:
    return dummy->next;
}

int main()
{

    int N = 2;

    // Create list:

    Node *head = new Node();
    head->val = 0;
    head->next = NULL;

    Node *second = new Node();
    second->val = 2;
    second->next = NULL;
    head->next = second;

    Node *third = new Node();
    third->val = 4;
    third->next = NULL;
    second->next = third;

    Node *fourth = new Node();
    fourth->val = 6;
    fourth->next = NULL;
    third->next = fourth;

    // Call the Remove function:
    Remove ( head , N);

    return 0;
}