// Problem : implement max heap

// Approach: Insert- Parent index is calculated as (index-1)/2 for every node being pushed, value is compared with parent node and swapped accordingly
//           Delete- Root is assigned val equal to last node and last node is popped, then the new root is heapified
//           Heapify- In a CBT Leaf nodes range from (n/2+1) to n where n is array size and they are heap on their own, other nodes are checked and heapified
//           Heap Sort- 1st and last elements are swapped and then size--, repeated until all the elements are in a sorted order, root node is heapified. TC: O(nlogn)

#include <iostream>
#include <vector>
using namespace std;

class Heap
{
public:
    vector<int> nodes;

    void insert(int val)
    {
        nodes.push_back(val);
        int index = nodes.size() - 1;

        while (index > 0)
        {
            int parent_index = (index - 1) / 2;
            if (nodes[parent_index] < nodes[index])
            {
                swap(nodes[parent_index], nodes[index]);
                index = parent_index;
            }
            else
                break;
        }
    }

    void deleteRoot()
    {
        if (nodes.empty())
            return;

        nodes[0] = nodes.back();
        nodes.pop_back();
        int index = 0;

        while (true)
        {
            int leftIndex = 2 * index + 1;
            int rightIndex = 2 * index + 2;
            int largestIndex = index;

            if (leftIndex < nodes.size() && nodes[leftIndex] > nodes[largestIndex])
            {
                largestIndex = leftIndex;
            }
            if (rightIndex < nodes.size() && nodes[rightIndex] > nodes[largestIndex])
            {
                largestIndex = rightIndex;
            }

            if (largestIndex != index)
            {
                swap(nodes[index], nodes[largestIndex]);
                index = largestIndex;
            }
            else
                break;
        }
    }

    void printNodes()
    {
        for (int node : nodes)
            cout << node << " ";
        cout << endl;
    }
};

void Heapify(vector<int> &nums, int i, int n)
{
    int largest_idx = i;
    int left_idx = 2 * i + 1;
    int right_idx = 2 * i + 2;

    if (left_idx < n && nums[left_idx] > nums[largest_idx])
        largest_idx = left_idx;
    if (right_idx < n && nums[right_idx] > nums[largest_idx])
        largest_idx = right_idx;

    if (largest_idx != i)
    {
        swap(nums[i], nums[largest_idx]);
        Heapify(nums, largest_idx, n);
    }
}

void HeapSort(vector<int> &nums)
{
    int n = nums.size();
    if (n < 2)
        return;

    // Step 1: Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        Heapify(nums, i, n);
    }

    // Step 2: Extract elements one by one
    for (int i = n - 1; i > 0; i--)
    {
        swap(nums[0], nums[i]);
        Heapify(nums, 0, i);
    }
}

int main()
{
    Heap H;
    H.insert(10);
    H.insert(5);
    H.insert(1);
    H.insert(6);
    H.insert(8);

    cout << "Heap: ";
    H.printNodes();

    H.deleteRoot();
    cout << "After deletion: ";
    H.printNodes();

    vector<int> nums = {54, 53, 55, 52, 50};

    cout << "Before Heapifying: ";
    for (int val : nums)
        cout << val << " ";
    cout << endl;

    for (int i = nums.size() / 2 - 1; i >= 0; i--)
    {
        Heapify(nums, i, nums.size());
    }

    cout << "After heapifying: ";
    for (int val : nums)
        cout << val << " ";
    cout << endl;

    cout << "Before Heap Sort: ";
    for (int val : nums)
        cout << val << " ";
    cout << endl;

    HeapSort(nums);

    cout << "After Heap Sort: ";
    for (int val : nums)
        cout << val << " ";
    cout << endl;

    return 0;
}
