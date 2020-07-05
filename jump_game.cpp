#include <unordered_map>
#include <vector>

bool helper(const std::vector<int>& nums, int start, std::unordered_map<int,bool>& dp)
{
    if(dp.find(start) != dp.end())
        return dp[start];
    
    if(start >= nums.size() - 1)
        return true;
    
    for(int i = nums[start]; i > 0; i--)
        if(helper(nums, start + i, dp))
        {
            dp[start] = true;
            return true;
        }
    dp[start] = false;
    return false;
}

// Time limit exceeds with this solution
bool canJump_recur_DP(std::vector<int>& nums)
{
    std::unordered_map<int,bool> dp;
    return helper(nums, 0, dp);
}

// Time limit exceeds with this solution
bool canJump_forward_DP(const std::vector<int>& nums)
{
    std::vector<bool> dp(nums.size());
    dp[0] = true;
    for(int i = 0; i < nums.size(); i++)
    {
        if(dp[i])
        {
            if(i + nums[i] >= nums.size())
                return true;
            for(int j = i+1; j <= i + nums[i]; j++)
                dp[j] = true;
        }
    }
    return dp[nums.size()-1];
}

bool canJump_iter(std::vector<int>& nums)
{
    int reachable = 0;
    for(int i = 0; i <= reachable; i++)
    {
        reachable = std::max(reachable, nums[i]+i);
        if(reachable >= nums.size()-1)
            return true;
    }
    return reachable >= nums.size()-1;
}

int main()
{

}