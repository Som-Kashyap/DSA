#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int RowWithMaxOnes(vector<vector<int>> &mat)
{
    int m = mat.size(), n = mat[0].size();
    vector<int> ans;
    int MaxOnes = 0;
    int count = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 1)
            {
                count++;

                if (count > MaxOnes)
                {
                    MaxOnes = count;
                    ans.push_back(i);
                    ans.push_back(count);
                }
            }
            else
            {
                continue;
            }
        }
    }
        for (int val : ans)
        {
            return val;
        }cout<<ans.size()<<endl;
        
    }

    int main()
    {
        vector<vector<int>> mat = {{1, 2, 3}, {1, 1, 1}, {1, 1, 2}};
        cout << RowWithMaxOnes(mat) << endl;
        return 0;
    }