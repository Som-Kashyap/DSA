#include <iostream>
#include <vector>
using namespace std;

int LowerTraingularSum(vector<vector<int>> &mat)
{
    int m = mat.size(), n = mat[0].size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i<j)
            {
                sum += mat[i][j];
            }
        }
    }
    return sum ;
}
int main()
{
    vector<vector<int>> mat = {{1, 2, 3, 4} ,{5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    cout << LowerTraingularSum(mat) << endl;

    return 0;
}
