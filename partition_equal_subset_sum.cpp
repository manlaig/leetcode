#include <unordered_set>
#include <vector>
using namespace std;

// Solution 1
bool canPartition(const vector<int>& nums)
{
    if(!nums.size() || nums.size() == 1)
        return false;
    
    int sum = 0;
    for(int num : nums)
        sum += num;
    
    if(sum % 2)
        return false;
    
    sum /= 2;
    
    // dp[i][sum] = can partition the rest of the array
    // if set 1 has 'sum' by including elements up to index i
    vector<unordered_set<int>> dp(nums.size());
    dp[0] = { nums[0], 0 };
    
    int so_far = nums[0];
    for(int i = 1; i < nums.size(); i++)
    {
        so_far += nums[i];
        for(int num : dp[i-1])
        {
            if(nums[i] + num == sum)
                return true;
            else if(nums[i] + num < sum)
                dp[i].insert(nums[i] + num);
            if(so_far - num <= sum)
                dp[i].insert(num);
        }
    }
    return false;
}

// Solution 2
bool canPartition_dfs(const vector<int>& nums)
{
    if(!nums.size() || nums.size() == 1)
        return false;
    
    int sum = 0;
    for(int num : nums)
        sum += num;
    
    if(sum % 2)
        return false;
    
    sum /= 2;
    
    std::function<bool(int, int)> dfs = [&](int left, int i)
    {
        if(left == 0)
            return true;
        bool found = false;
        for(int curr = i+1; curr < nums.size(); curr++)
        {
            if(left - nums[curr] >= 0)
                found |= dfs(left - nums[curr], curr);
            if(found)
                return true;
        }
        return false;
    };
    return dfs(sum, 0);
}

int main()
{
    
}