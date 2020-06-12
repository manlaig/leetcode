#include <unordered_map>
#include <vector>

// Time limit exceeds with this solution
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

bool canJump_recur(std::vector<int>& nums)
{
    std::unordered_map<int,bool> dp;
    return helper(nums, 0, dp);
}

bool canJump_iter(vector<int>& nums)
{
    int reachable = 0;
    for(int i = 0; i <= reachable; i++)
    {
        reachable = max(reachable, nums[i]+i);
        if(reachable >= nums.size()-1)
            return true;
    }
    return reachable >= nums.size()-1;
}

int main()
{

}