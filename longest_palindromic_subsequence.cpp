#include <vector>
#include <string>
using namespace std;

int helper(const string& s, int left, int right, vector<vector<int>>& dp)
{
    if(dp[left][right])
        return dp[left][right];
    if(right <= left)
    {
        dp[left][right] = 1;
        return 1;
    }
    if(right - left == 1)
    {
        dp[left][right] = s[right] == s[left] ? 2 : 1;
        return dp[left][right];
    }
    if(s[left] == s[right])
    {
        dp[left][right] = helper(s, left + 1, right - 1, dp) + 2;
        return dp[left][right];
    }
    dp[left][right] = max(helper(s, left+1, right, dp), helper(s, left, right-1, dp));
    return dp[left][right];
}

int longestPalindromeSubseq(string s)
{
    if(!s.size())
        return 0;
    vector<vector<int>> dp(s.size(), vector<int>(s.size()));
    return helper(s, 0, s.size()-1, dp);
}

int main()
{

}