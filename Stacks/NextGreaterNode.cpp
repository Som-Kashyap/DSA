#include<iostream>
#include<stack>
#include<vector>

using namespace std;

struct Node{
    int val;
    Node* next;

};

vector<int> NextGreaterNode(Node* head){

    vector<int>list;
    
    stack<int>st;

    while ( head!=NULL ) {
        list.push_back ( head->val );
        head = head->next;
    }

    int n = list.size();
    vector<int>ans(n,0);
    for ( int i = 0; i < list.size(); i++ ){

        while ( !st.empty() && list[i]> list[st.top()] ) {

            ans[st.top()]=list[i];
            st.pop();

        }
        st.push(i);
    }
    return ans;
}

int main () {

    Node* head = new Node;
    head -> val = 2;
    head -> next = NULL;

    Node* first = new Node;
    first -> val = 1;
    first -> next = NULL;
    head -> next = first;

    Node* second = new Node;
    second -> val = 5;
    second -> next = NULL;
    first -> next = second;

    vector<int>ans = NextGreaterNode(head);

   for ( int val:ans){
    cout<<val<<" ";
   }
   cout<<endl;

    return 0;
}