#include <iostream>
#include <climits>
using namespace std;

int GetMaxSum(int matrix[3][3], int rows, int cols)
{
    int maxSum = INT_MIN;
    for (int i = 0; i < cols; i++)
    {
        int sum = 0;
        for (int j = 0; j < rows; j++)
        {
            sum += matrix[i][j];
        }
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}
int main()
{
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int rows = 3, cols = 3;

    cout << "Max column sum: " << GetMaxSum(matrix, rows, cols) << endl;
    return 0;
}