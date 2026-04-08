#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseQueue( queue<int>& q ) {

   stack<int> st;

   
   while (!q.empty()) {

       st.push(q.front());
       q.pop();

   }
  
   while (!st.empty()) {

       q.push(st.top());
       st.pop();

   }

}
int main() {

   queue<int> q;

   q.push(10);
   q.push(100);
   q.push(-10);

   reverseQueue(q);

   while (!q.empty()) {

       cout << q.front() << " ";
       q.pop();

   }

   return 0;
}