#include <string>
#include <vector>
using namespace std;

// more space efficient than the other iterative approach
int longestCommonSubsequence(string text1, string text2)
{
    // in some DP problems, you can have a 1D table and you can start from right to left
    // but in this problem, we need to access the left element that's computed in the prev iteration
    // so we need to keep the current row and the previous row, everything before can be thrown away
    // so that's where the 2 comes from, one is previous row and other is current row
    // which one we access is determined by i % 2
    vector<vector<int>> dp(2, vector<int>(text2.size()));
    
    for(int i = 0; i < text1.size(); i++)
    {
        bool odd = i % 2;
        for(int j = 0; j < text2.size(); j++)
        {
            if(text1[i] == text2[j])
                dp[odd][j] = 1 + (i-1 >= 0 && j-1 >= 0 ? dp[!odd][j-1] : 0);
            else
                dp[odd][j] = max(i-1 >= 0 ? dp[!odd][j] : 0, j-1 >= 0 ? dp[odd][j-1] : 0);
        }
    }
    return max(dp[1][text2.size()-1], dp[0][text2.size()-1]);
}

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

int longestCommonSubsequence_recur(string text1, string text2)
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

int main()
{

}