// Problem LC: 23

// Approach: A min-heap is used to stored heads of the k lists, a dummy node is created and the nodes are linked in a sorted order
//           node->next is pushed after popping the top if it exists.

//  TC: O(nlogk)
//  SC: O(k)

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct ListNode{

    int val;
    ListNode* next;

    ListNode( int data ) {
        val = data;
        ListNode* next = NULL;
    }
};

struct Compare{

    bool operator() (ListNode* a , ListNode* b){
                return a->val > b ->val;
    }
};

ListNode* mergeKLists ( vector<ListNode*>lists ) {

    priority_queue<ListNode* , vector<ListNode*> , Compare> pq;
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;

    for ( auto node : lists ) if ( node ) pq.push( node );

    while ( !pq.empty() ) {

        ListNode* smallest = pq.top();
        pq.pop();

        curr->next = smallest;
        curr = curr->next;

        if ( smallest->next ) pq.push ( smallest -> next );

    }
    curr->next = NULL;

    return dummy->next;
}
