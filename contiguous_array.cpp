#include <unordered_map>
#include <vector>

int findMaxLength(std::vector<int>& nums)
{
    if(!nums.size())
        return 0;
    std::unordered_map<int, int> sum;
    sum[0] = -1;
    int total = 0;
    int max = 0;
    
    for(int i = 0; i < nums.size(); i++)
    {
        total += nums[i] ? 1 : -1;
        if(sum.find(total) == sum.end())
            sum[total] = i;
        else
            max = std::max(max, i - sum[total]);
    }
    
    return max;
}

int findMaxLength_slow(std::vector<int>& nums)
{
    if(!nums.size())
        return 0;
    std::vector<int> sum(nums.size());
    sum[0] = nums[0] ? 1 : -1;
    
    for(int i = 1; i < nums.size(); i++)
        sum[i] = (nums[i] ? 1 : -1) + sum[i-1];
    
    int max = 0;
    std::unordered_map<int, int> occur;
    occur[0] = -1;
    
    for(int i = 0; i < sum.size(); i++)
        if(occur.find(sum[i]) == occur.cend())
            occur[sum[i]] = i;
        else
            max = std::max(max, i - occur[sum[i]]);
    
    return max;
}

int main()
{

}