#include<iostream>
#include<queue>

using namespace std;

class Queue {
    
    int size = 5;
    int arr[5];
    int f, e;

public:
    Queue() {
        
        f = -1; 
        e = -1;

    }

    bool isEmpty() {

        return (f == -1 || f > e);

    }

    void emplace(int el) {

        if (e == size - 1) {

            cout << "Queue is full!" << endl;
            return;

        }

        if (isEmpty()) {

            f = 0; 

        }

        arr[++e] = el; 
    }

    void dequeue() {

        if (isEmpty()) {

            cout << "Queue is empty!" << endl;
            return;

        }

      
        f++;
        if (f > e) { 

            f = -1;
            e = -1;

        }
    }

    void display() {

        if (isEmpty()) {

            cout << "Queue is empty!" << endl;
            return;

        }

        for (int i = f; i <= e; i++) {

            cout << arr[i] << " ";

        }
        cout << endl;
    }
};

int main() {

    Queue q;
    q.emplace(5);
    q.emplace(10);
    q.display(); 
    q.dequeue(); 
    q.display(); 

    return 0;
}
