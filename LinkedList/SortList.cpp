#include<iostream>
#include<list>

using namespace std;

struct Node{
     int val;
    Node* next;
};

Node* Merge (Node* l1 , Node* l2 , Node* head ) {

    
    Node* dummy = new Node() ;
    Node* tail = dummy;

  
    while ( l1 != NULL && l2 != NULL ) {

        if ( l1 -> val <= l2 -> val ) {
            tail -> next = l1;
            tail = tail->next;
        }else{
            tail -> next = l2;
            tail = tail->next;
        }
    }
    if ( l1 != NULL ) {
        tail -> next = l1;
    }
     else {
        tail -> next = l2;
     }
  
     return dummy->next;
    
}

Node* Sort ( Node* head ) {

    Node* temp = NULL;
    Node* slow = head ;
    Node* fast = head ;

    while ( fast != NULL ) {

        temp = slow;
        slow = slow -> next;
        fast = fast -> next -> next;
        

    }
    temp->next=NULL;
 

    Node* l1 = Sort ( head );
    Node* l2 = Sort ( head );
    return Merge ( l1 , l2, head) ;
}