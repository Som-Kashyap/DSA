#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int RepeatingAndMissing(vector<vector<int>> &mat)
{
    
    set<int> Repeating;
    int n=mat.size();
    int a;int b;int ExpSum=(n*n*(n*n+1)/2);int ActSum=0;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (Repeating.find(mat[i][j]) != Repeating.end())
            {
                a = mat[i][j];
                ans.push_back(mat[i][j]);
                
            }
            else
            {
                Repeating.insert(mat[i][j]);
            }
            ActSum+=mat[i][j];
        }
    }
    b=ExpSum+a-ActSum;
    ans.push_back(b);
   
    cout<<"Duplicate ans Missing respectfully. "<<endl;
    for (int val : ans)
    {
        return val;
    }
}
int main()
{
    vector<vector<int>> mat = {{9, 1, 2}, {3, 4, 5}, {9, 7, 6}};
    cout << RepeatingAndMissing(mat) << endl;
    return 0;
}