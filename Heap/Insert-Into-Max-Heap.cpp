// Problem : Insert into max heap

// Approach: Parent index is calculated as (index-1)/2 for every node being pushed, value is compared with parent node and swapped accordingly

#include<iostream>
#include<vector>

using namespace std;

class Heap {

    public:
    
    vector<int>nodes;

    void insert( int val ) {

        nodes.push_back( val );

        int index = nodes.size()-1;

        while( index > 0 ) {

            int parent_index =(index-1)/2;

            if( nodes[parent_index] < nodes[index] ) {

                swap( nodes[parent_index] , nodes[index] );
                index = parent_index;
            }
            else return;
        }
    }
    
    void printNodes() {

        for( int node : nodes ) {

            cout<<node<<" ";
        }
        cout<<endl;
    }
};

int main() {

    Heap H;

    H.insert(10);
    H.insert(5);
    H.insert(1);
    H.insert(6);
    H.insert(8);

    H.printNodes();

    return 0;

}