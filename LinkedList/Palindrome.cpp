#include<iostream>

using namespace std;

struct Node{

    int val;
    Node* next;

};

void Reverse ( Node* head , Node* slow ) {

    Node* prev = slow;
    Node* curr = slow -> next;

    while ( curr != NULL ) {

        Node* nextnode = curr->next;
        curr -> next = prev;
        prev = curr;
        curr = nextnode;

    }
}

bool Palindrome ( Node* head ) {

    // create pointers to find middle:
    Node* slow = head;
    Node* fast = head;

    while ( fast != NULL ) {

        slow = slow -> next;
        fast = fast -> next -> next;

    }
    // adjustment for odd length lists , since mid does not contribute to palindrome symmetry.
    if ( fast != NULL ) {

        slow = slow->next;

    }

    // Compare the two halves
    Node* firsthalf = head;
    Node* secondhalf = slow;
   
    while ( secondhalf ) {

        if ( firsthalf -> val != secondhalf -> val ) {
            return false;
        }
        firsthalf = firsthalf -> next;
        secondhalf = secondhalf -> next;
    }
    return true;

}