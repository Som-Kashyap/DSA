
// Problem #3217 Leetcode.
// Statement : Delete Nodes From LinkedList Present In Array.

// Approach : Use set to stores elements of the array. Move the head pointer till it's value exists in the set.
//             Move curr pointer if the value of curr->next is not there in the set , otherwise remove next element.

// Result : Head pointer ends at the starting node of the modified LinkedList

#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>

using namespace std;

struct Node{
    int val;
    Node* next;
};

vector<int> DeleteNodes ( vector<int>& nums , Node* head ) {

    unordered_set<int>numsset (nums.begin() , nums.end());

    Node* dummy = new Node;
    dummy -> val = NULL;
    dummy -> next = head;

    Node* curr = head;

    while ( head && numsset.count(head->val) ) head = head->next;

    while ( curr && curr->next ) {

        while ( curr->next && numsset.count(curr->next->val) ) {
            curr->next = curr->next->next;
        }

        curr = curr->next;

    }

   return head;
   
}