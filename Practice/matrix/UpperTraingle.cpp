#include <iostream>
#include <vector>
using namespace std;

void UpperTraingle(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i < j)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
}
int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    UpperTraingle(matrix);

    return 0;
}