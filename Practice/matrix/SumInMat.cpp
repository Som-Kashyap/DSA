#include <iostream>
#include <vector>
using namespace std;

int Sum(vector<vector<int>> &mat)
{
    int m = mat.size(), n = mat[0].size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
            sum += mat[i][j];
        }
    }
    return sum;
}

int main()
{
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "Sum of elements: " << Sum(mat) << endl;
}