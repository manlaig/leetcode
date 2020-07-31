#include <unordered_map>
#include <vector>
using namespace std;

// O(N * 2000) algorithm 
int findTargetSumWays(vector<int>& nums, int S)
{
    if(!nums.size() || S > 1000)
        return 0;
    vector<vector<int>> dp(nums.size(), vector<int>(2001));
    dp[0][nums[0]+1000] = 1;
    dp[0][-nums[0]+1000] += 1;
    
    for(int i = 1; i < nums.size(); i++)
    {
        for(int j = -1000; j <= 1000; j++)
        {
            if(dp[i-1][j+1000] > 0)
            {
                if(j+nums[i]+1000 <= 2000)
                    dp[i][j+nums[i]+1000] += dp[i-1][j+1000];
                if(j-nums[i]+1000 >= 0)
                    dp[i][j-nums[i]+1000] += dp[i-1][j+1000];
            }
        }
    }
    return dp[nums.size()-1][S+1000];
}

// O(N * 2^n) algorithm
int findTargetSumWays_slow(vector<int>& nums, int S)
{
    if(!nums.size())
        return 0;
    unordered_map<int, int> dp[nums.size()];
    dp[0][nums[0]] += 1;
    dp[0][-nums[0]] += 1;
    
    for(int i = 1; i < nums.size(); i++)
    {
        for(auto p : dp[i-1])
        {
            dp[i][p.first + nums[i]] += p.second;
            dp[i][p.first - nums[i]] += p.second;
        }
    }
    return dp[nums.size()-1][S];
}

int main()
{

}