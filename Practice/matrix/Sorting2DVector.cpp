#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Sorting(vector<vector<int>> &mat)
{
    int m = mat.size(), n = mat[0].size();
    vector<int> linear;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            linear.push_back(mat[i][j]);
        }
    }
    sort(linear.begin(), linear.end());
    for (int i1 = 0; i1 < m; i1++)
    {
        for (int j1 = 0; j1 < n; j1++)
        {
            mat[i1][j1] == linear[n * i1 + j1];
        }
    }
    for (int i2 = 0; i2 < m; i2++)
    {
        for (int j2 = 0; j2 < n; j2++)
        {
            cout << mat[i2][j2]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    vector<vector<int>> mat = {{21, 32, 11}, {42, 57, 12}, {57, 23, 41}};
    Sorting(mat);
    return 0;
}