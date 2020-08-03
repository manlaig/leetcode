#include <vector>

// O(N) time and O(1) space
int rob(const std::vector<int>& nums)
{
    if(!nums.size())
        return 0;
    if(nums.size() == 1)
        return nums[0];
    if(nums.size() == 2)
        return std::max(nums[0], nums[1]);
    if(nums.size() == 3)
        return std::max(nums[2] + nums[0], nums[1]);

    int one = nums[0];
    int two = nums[1];
    int three = nums[2] + one;
    int four = nums[3] + std::max(two, one);
    
    for(int i = 4; i < nums.size(); i++)
    {
        int temp = four;
        four = nums[i] + std::max(three, two);
        one = two;
        two = three;
        three = temp;
    }
    
    return std::max(four, three);
}

int rob_DP(const std::vector<int>& nums)
{   
    if(!nums.size())
        return 0;
    // nums.size() returns an unsigned number, so we can check like nums.size() - 2 >= 0
    int n = nums.size();
    int m[n];
    for(int i = 0; i < n; i++)
    {
        if(i < 2)
            m[i] = nums[i];
        else
            m[i] = nums[i] + std::max(m[i-2], i-3 >= 0 ? m[i-3] : 0);
    }   
    return std::max(m[n-1], n-2 >= 0 ? m[n-2] : 0);
}

int main()
{
    
}