#include<iostream>

using namespace std;

struct Node{

    int val;
    Node* next;

};

bool Cycle ( Node* head ) {

    Node* slow = head;
    Node* fast = head;

    while ( fast!=NULL && fast->next!=NULL ) {

        slow = slow -> next;
        fast = fast -> next -> next;

        if ( slow == fast ) {

            return true;

        }
    }
    return false;
}
