#include <unordered_set>
#include <vector>
using namespace std;

// Solution 5 (Solution 4 optimized)
bool canPartition_1D_optimized(const vector<int>& nums)
{
    if(!nums.size() || nums.size() == 1)
        return false;
    
    int sum = 0;
    for(int num : nums)
        sum += num;
    
    if(sum % 2)
        return false;
    
    sum /= 2;
    
    // from solution 3, we can see that we only need the values from 
    // the last row, so we can reduce a 2D table to 1D
    // last[sum] = can partition sum using elements up to i
    vector<bool> last(sum+1);
    
    for(int i = 0; i < nums.size(); i++)
    {
        /*
            if we start from 0, then the test [1,2,5] fails because
            it allows using the same element twice because we access dp[num-nums[i]]
            in other words, we're accessing elements in our current row

            so we start from the right side because we don't access elements to the right
        */
        for(int num = sum; num >= 0; num--)
        {
            if(num == 0)
            {
                last[num] = true;
            }
            else if(i == 0)
            {
                last[num] = num - nums[i] == 0;
            }
            else if(num - nums[i] >= 0)
            {
                last[num] = last[num] || last[num-nums[i]];
            }
        }
    }
    return last[sum];
}

// Solution 4
bool canPartition_1D(const vector<int>& nums)
{
    if(!nums.size() || nums.size() == 1)
        return false;
    
    int sum = 0;
    for(int num : nums)
        sum += num;
    
    if(sum % 2)
        return false;
    
    sum /= 2;
    
    // from solution 3, we can see that we only need the values from 
    // the last row, so we can reduce a 2D table to 1D
    // last[sum] = can partition sum using elements up to i
    vector<bool> last(sum+1);
    vector<bool> curr(sum+1);
    
    for(int i = 0; i < nums.size(); i++)
    {
        for(int num = 0; num <= sum; num++)
        {
            if(num == 0)
            {
                curr[num] = true;
            }
            else if(i == 0)
            {
                curr[num] = num - nums[i] == 0;
            }
            else
            {
                if(num - nums[i] < 0)
                    curr[num] = last[num];
                else
                    curr[num] = last[num] || last[num-nums[i]];
            }
        }
        last = curr;
    }
    return curr[sum];
}

// Solution 3, faster and space efficient than solution 1
bool canPartition_2D(const vector<int>& nums)
{
    if(!nums.size() || nums.size() == 1)
        return false;
    
    int sum = 0;
    for(int num : nums)
        sum += num;
    
    if(sum % 2)
        return false;
    
    sum /= 2;
    
    // dp[i][sum] = can partition sum using elements up to i
    vector<vector<bool>> dp(nums.size(), vector<bool>(sum+1));
    
    for(int i = 0; i < nums.size(); i++)
    {
        for(int num = 0; num <= sum; num++)
        {
            if(num == 0)
            {
                dp[i][num] = true;
            }
            else if(i == 0)
            {
                dp[i][num] = num - nums[i] == 0;
            }
            else
            {
                if(num - nums[i] < 0)
                    dp[i][num] = dp[i-1][num];
                else
                    dp[i][num] = dp[i-1][num] || dp[i-1][num-nums[i]];
            }
        }
    }
    return dp[nums.size()-1][sum];
}

// Solution 1
bool canPartition_slow(const vector<int>& nums)
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

// Solution 2, time limit exceed since it explores 2^n possibilities
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