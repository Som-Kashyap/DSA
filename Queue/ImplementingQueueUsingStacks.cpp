
// Problem : Implementing queue using stacks

// Approach : Two stacks are created , elements are pushed into the 1st stack , then all the elements are copied to stack 2 ( hence , revsering the order ) , therefore now stack operations simulate a queue

#include<iostream>
#include<stack>

using namespace std;

class Queue {

    private:
    stack<int>StIn;
    stack<int>StOut;

    public:

    void enqueue( int val );
    void transfer();
    void dequeue();
    int front();

};

 void Queue :: enqueue( int val ) {

    StIn.push ( val );

}

void Queue :: transfer () {

    while ( !StIn.empty() ) {

        StOut.push ( StIn.top() );
        StIn.pop();

    }
}

void Queue :: dequeue () {

    if ( StOut.empty() ) {

        transfer();

    }

    if ( StOut.empty() ) {

        throw runtime_error("Queue is empty!");

    }
}

int Queue :: front () {

    if ( !StOut.empty() ) {

        return StOut.top();

    }

    throw runtime_error("Queue is empty!");

}

int main () {

    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    q.dequeue();
    q.dequeue();

    return 0;

}