#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int heightChecker(vector<int> &heights)
{

    vector<int> Expected;

    int wrong = 0;

    for (int i = 0; i < heights.size(); i++)
    {
        Expected.push_back(heights[i]);
    }
    sort(Expected.begin(), Expected.end());

    for (int x = 0; x < heights.size(); x++)
    {
        

            if (heights[x] != Expected[x])
            {
                wrong++;
            }
        
    }

    return wrong;
}
int main()
{

    vector<int> heights = {1, 1, 4, 2, 1, 3};

    cout << heightChecker(heights) << endl;

    return 0;
}