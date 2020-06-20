#include <string>
#include <vector>
using namespace std;

int helper(const string& s1, const string& s2, int i1, int i2, vector<vector<int>>& m)
{
    if(i1 == s1.size() || i2 == s2.size())
        return 0;
    
    if(m[i1][i2])
        return m[i1][i2];
    
    if(s1[i1] == s2[i2])
        m[i1][i2] = 1 + helper(s1, s2, i1+1, i2+1, m);
    else
        m[i1][i2] = max(helper(s1, s2, i1+1, i2, m),
                        helper(s1, s2, i1, i2+1, m));
    return m[i1][i2];
}

int longestCommonSubsequence(string text1, string text2)
{
    vector<vector<int>> m(text1.size(), vector<int>(text2.size()));
    return helper(text1, text2, 0, 0, m);
}

int longestCommonSubsequence_iter(string text1, string text2)
{   
    int n1 = text1.size();
    int n2 = text2.size();
    
    int m[n1][n2];
    
    for(int i = 0; i < n1; i++)
    {
        for(int j = 0; j < n2; j++)
        {
            if(text1[i] == text2[j])
                m[i][j] = 1 + (i-1 >= 0 && j-1 >= 0 ? m[i-1][j-1] : 0);
            else
            {
                int p1 = j-1 >= 0 ? m[i][j-1] : 0;
                int p2 = i-1 >= 0 ? m[i-1][j] : 0;
                m[i][j] = max(p1, p2);
            }
        }
    }
    return m[n1-1][n2-1];
}