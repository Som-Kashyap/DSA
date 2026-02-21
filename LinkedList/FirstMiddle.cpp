#include<iostream>

using namespace std;

struct Node {

    int val;
    Node* next;

};

Node* Middle ( Node* head ) {

    Node* slow = head;
    Node* fast = head;

    while ( fast!=NULL || fast->next->next!=NULL ) {

        slow = slow -> next;
        fast = fast -> next -> next;

    }
    return slow;
}