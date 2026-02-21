#include <iostream>
#include <vector>

using namespace std;

int AssignCookies(vector<int> &g, vector<int> &s)
{
    // If for some value of i , there exists a value of j such that s[j]>=g[i], ans++. Move to next value of i and repeat.
    
    int ans = 0;

    int i = 0;
    int j = 0;

    while (i < g.size() && j < s.size())
    {

        if (g[i] <= s[j])
        {
            ans += 1;
            i++;
            j = 0;
        }
        else
        {
            j++;
        }
    }

    return ans;
}
int main()
{
    vector<int> g = {1, 2};
    vector<int> s = {1, 2 ,3};

    cout << AssignCookies << endl;

    return 0;
}