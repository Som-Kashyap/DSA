#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxElement(vector<vector<int>> &mat)
{
    int m = mat.size(), n = mat[0].size();
    int largest = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] > largest)
            {
                largest = mat[i][j];
            }
          
        }
    }
  return largest;
}
int main()
{
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "Largest Elements: " << maxElement(mat) << endl;
    return 0;
}