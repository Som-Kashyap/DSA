#include<iostream>

using namespace std;

struct Node {
    int val;
    Node* next;
};

Node* DetectCycleII(Node* head) {
    Node* slow = head, *fast = head;

    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast) break; 
    }

    if (!(fast && fast->next)) return NULL;

    while (head != slow) {
        head = head->next;
        slow = slow->next;
    }
    return head; 
}

int main() {
    Node* head = new Node;
    head->val = 3;
    head->next = NULL;

    Node* first = new Node;
    first->val = 2;
    first->next = NULL;
    head->next = first;

    Node* second = new Node;
    second->val = 0;
    second->next = NULL;
    first->next = second;

    Node* third = new Node;
    third->val = 4;
    third->next = first;
    second->next = third;

    Node* cycleStart = DetectCycleII(head);
    
    if (cycleStart) {
        cout << "Cycle detected at node with value: " << cycleStart->val << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    return 0;
}
