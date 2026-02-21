#include<iostream>

using namespace std;

struct Node{
    int val;
    Node* next;
};

Node* ReverseKNodes ( Node* head , int K ) {

    // Create pointer initiating from the head:
    Node* temp = head;
   
    // Checking list length:
    for ( int i = 0; i < K; i++ ){

        if ( temp == NULL ) {
            return head;
        }
        temp = temp -> next;

    }
    
    Node* prev = NULL;
    Node* curr = head;
    int count = 0;

    while ( count < K ) {

        Node* nextnode = curr -> next;

        curr -> next = prev;
        prev = curr;
        curr = nextnode;

        count++;

    }

    head -> next = ReverseKNodes ( curr , K );

    return prev;


}
int main () {

    int K = 2;

    Node* head = new Node();
    head -> val = 1;
    head -> next = NULL;

    Node* second = new Node();
    second -> val = 2;
    second -> next = NULL;
    head -> next = second;

    Node* third = new Node();
    third -> val = 3;
    third -> next = NULL;
    second -> next = third;

    Node* fourth  = new Node();
    fourth -> val = 4;
    fourth -> next = NULL;
    third -> next = fourth;

    Node* fifth = new Node();
    fifth -> val = 5;
    fifth -> next = NULL;
    fourth -> next = fifth;

    //update head to the new head:
    head = ReverseKNodes ( head , K);

    Node* Temp = head;

    while ( Temp != NULL ) {
        cout << Temp -> val << "-> ";
        Temp = Temp -> next;
    }
    cout<<"NULL"<<endl;

    return 0;
}