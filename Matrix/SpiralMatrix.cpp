#include <iostream>
#include <vector>
using namespace std;

void Spiral(vector<vector<int>> &mat)
{
    
    int m = mat.size(), n = mat[0].size();
    int srow = 0, scol = 0, erow = m - 1, ecol = n - 1;
    vector<int> ans;
    while(srow<erow && scol<=ecol){
    for (int j = srow; j < n; j++)
    {
        ans.push_back(mat[srow][j]);
    }
    for (int j = srow + 1; j < m; j++)
    {
        ans.push_back(mat[j][ecol]);
    }
    for (int j = ecol - 1; j >= 0; j++)
    {
        ans.push_back(mat[erow][j]);
    }
    for (int j = erow - 1; j < srow; j++)
    {
        ans.push_back(mat[j][scol]);
    }
    ecol--;
    srow++;
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    vector<vector<int>> mat = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 20, 24}, {18, 21, 23, 26, 30}};
   Spiral(mat);
    return 0;
}