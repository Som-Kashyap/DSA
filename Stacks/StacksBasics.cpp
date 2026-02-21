#include<iostream>
#include<vector>

using namespace std;

class Stack {

vector<int>stack;

    public:

    void push ( int x ) {

        stack.push_back(x);

    }
    void pop () {

        stack.pop_back();

    }
    int top() {

        return stack[stack.size()-1];

    }
    bool empty () {

        return stack.size() == 0;

    }
};

int main () {

    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    while ( !s.empty() ) {

        cout<< s.top() <<" ";
        s.pop();
    }
    cout<<endl;

    return 0;

}
