#include<iostream>

using namespace std;

struct Node{
    int val;
    Node* next;

};
Node* Middle (Node* head ) {

    Node* slow = head;
    Node* fast = head;

    while ( fast != NULL && fast -> next != NULL ){

        slow = slow->next; //take the address in slow->next and put it into slow

        // pointers don't move , it is reassigned to another pointer index

        fast = fast -> next -> next;

    }
    return slow;
}