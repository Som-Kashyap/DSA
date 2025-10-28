#include <iostream>
using namespace std;

int DiagonalSum(int matrix[4][4], int rows, int cols,int n)
{
    for (int i = 0; i < rows; i++)
    {
        int sum = 0;
        for (int j = 0; j < cols; j++)
        {
            if (i == j)
            {
                sum += matrix[i][j];
            }
            else if (i != n - 1 - i)
            {
                sum += matrix[i][j];
            }
        }
        return sum;
    }
        
}
    
    int main()
    {
        int matrix[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
        int rows, cols, n = 4;
        cout << "Diagonal sum: " << DiagonalSum(matrix, rows, cols,n) << endl;
        return 0;
    }