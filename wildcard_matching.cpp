#include <vector>
#include <string>
using namespace std;

// In a DP problem, make sure you're finding the optimal solution for the subproblem BEFORE memoizing it

bool match(const string& s, const string& p, int i, int currP, vector<vector<int>>& dp)
{
    if(i >= s.size())
    {
        // if the remaining pattern is *s, then interpret them as empty sequences
        while(currP < p.size())
            if(p[currP++] != '*')
            {
                dp[i][currP] = false;
                return dp[i][currP];
            }
        dp[i][currP] = true;
        return dp[i][currP];
    }
    
    if(currP >= p.size())
    {
        dp[i][currP] = false;
        return dp[i][currP];
    }
    
    if(dp[i][currP] != -1)
        return dp[i][currP];
    
    // it's a match
    if(s[i] == p[currP] || p[currP] == '?')
    {
        dp[i][currP] = match(s, p, i+1, currP+1, dp);
        return dp[i][currP];
    }

    // can either include the current character to the sequence or end the sequence
    if(p[currP] == '*')
    {
        dp[i][currP] = match(s, p, i+1, currP, dp) || match(s, p, i, currP+1, dp);
        return dp[i][currP];
    }
    
    dp[i][currP] = false;
    return dp[i][currP];
}

bool isMatch(string s, string p)
{   
    vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1, -1));
    return match(s, p, 0, 0, dp);
}

int main()
{

}