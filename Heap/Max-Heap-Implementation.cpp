// Problem : implement max heap

// Approach: Insert- Parent index is calculated as (index-1)/2 for every node being pushed, value is compared with parent node and swapped accordingly
//           Delete- Root is assigned val equal to last node and last node is popped, then the new root is heapified
//           Heapify- In a CBT Leaf nodes range from (n/2+1) to n where n is array size and they are heap on their own, other nodes are checked and heapified

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

    void deleteRoot() {

        if( nodes.size() == 0 ) return;

        int size = nodes.size();

        nodes[0] = nodes[size-1];
        nodes.pop_back();
        size--;
        int index = 0;

        while( index < size ) {

        int leftIndex = 2*index+1;
        int rightIndex = 2*index+2;

        if( leftIndex < size && nodes[index] < nodes[leftIndex] ) {

            swap( nodes[index] , nodes[leftIndex] );
            index = leftIndex;

        }

        else if( rightIndex < size && nodes[index] < nodes[rightIndex] ) {

            swap( nodes[index] , nodes[rightIndex] );
            index = rightIndex;

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

void Heapify( vector<int>& nums , int i ) {

        int n = nums.size();

        int largest_idx = i;
        int left_idx = 2*largest_idx+1;
        int right_idx = 2*largest_idx+2;

        if( left_idx < n && nums[left_idx] > nums[largest_idx] ) largest_idx = left_idx;

        else if( right_idx < n && nums[right_idx] > nums[largest_idx] ) largest_idx = right_idx;

        if( largest_idx != i ) {
        swap( nums[largest_idx] , nums[i] );
        Heapify( nums , largest_idx );
        }
    }

int main() {

    Heap H;

    H.insert(10);
    H.insert(5);
    H.insert(1);
    H.insert(6);
    H.insert(8);

    cout<<"Heap: ";
    H.printNodes();
    
    
    H.deleteRoot();
    cout<<"After deletion: ";
    H.printNodes();

    vector<int>nums = {54,53,55,52,50};

    cout<<"Before Heapifying: ";
    for ( int val : nums ) {
        cout<<val<<" ";
    }
    cout<<endl;

    for ( int i = nums.size()/2; i >= 0; i-- ) {
        Heapify( nums , i );
    }

    cout<<"After heapifying: ";
    for ( int val : nums ) {
        cout<<val<<" ";
    }

    return 0;

}