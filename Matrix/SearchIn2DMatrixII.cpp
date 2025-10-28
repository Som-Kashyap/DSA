#include <iostream>
#include <vector>
using namespace std;

bool SearchMatrix(vector<vector<int>> &mat, int tar)
{
    int m = mat.size(), n = mat[0].size();
    int r = 0, c = n - 1;
    while (r < m && c>=0)
    {
        if (mat[r][c] == tar)
        {
            return true;
        }
        else if (mat[r][c] < tar)
        {
            r++;
        }
        else
        {
            c--;
        }
    }
    return false;
}
int main()
{
    vector<vector<int>> mat = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 20, 24}, {18, 21, 23, 26, 30}};
    int tar = 2;

    cout << SearchMatrix(mat, tar) << endl;
    return 0;
}