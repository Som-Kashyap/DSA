#include<iostream>
#include<vector>

using namespace std;

class Heap {

    vector<int>nodes;
    
    public:
   

    void insert( int val ) {

        nodes.push_back(val);
        int size = nodes.size();
        int index = size-1;

        while( index > 0 ) {

            int parent_index = (index-1)/2;

            if( nodes[index] < nodes[parent_index] ) {

                swap( nodes[index] , nodes[parent_index] );
                index = parent_index;

            }

            else return;

        }
    }

    void deleteRoot() {

        int size = nodes.size();

        if( size == 0 ) return;

        nodes[0] = nodes[size-1];
        nodes.pop_back();
        size--;
        int index = 0;

        while( true ) {

            int left_index = (2*index+1);
            int right_index = (2*index+2);
            int smallest;

            if( left_index < size && nodes[index] > nodes[left_index] ) smallest=left_index;

            if( right_index < size && nodes[index] > nodes[right_index] ) smallest=right_index;

            if( smallest != index ) {

                swap( nodes[index] , nodes[smallest] );
                index = smallest;

            }
            else break;;
        }
    }

    void getRoot() {

        if( nodes.size() == 0 ) {

            cout<<"Heap is empty!"<<endl;
            return ;

        }

         cout<<"Root: "<<nodes[0]<<endl;

    }
    void print() {

        cout<<"Min-Heap: ";

        for ( int node : nodes ) {

            cout<<node<<" ";
        }
        cout<<endl;
    }
};

int main () {

    Heap H;

    H.insert(5);
    H.insert(1);
    H.insert(0);
    H.insert(9);
    H.insert(7);

    H.print();
    H.getRoot();

    H.deleteRoot();
    cout<<"After deletion- ";
    H.print();
    H.getRoot();
    
    return 0;
}