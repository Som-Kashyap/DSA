#include<iostream>

using namespace std;

struct Node{
    int val;
    Node* next;
};

Node* Intersection ( Node* headA , Node* headB ) {

    Node* l1 = headA;
    Node* l2 = headB;
    Node* ans;

    while ( l1 != NULL && l2 != NULL ) {

        if ( l1 == l2 ) {
            return l1;
        }

        l1 = l1 -> next;
        l2 = l2 -> next;

        // If one pointer reaches NULL before the other and the relative velocity be them = 0 , and it is assigned value = other head , they eventually meet provided there is intersection bw the lists

        // Two pointers that traverse equal distances will meet at the head of intersection

    if ( l1==NULL ) {
        l1 = headB;
    }

    else if ( l2==NULL ) {
        l2 = headA;
    }

    }
    return 0;
    
}