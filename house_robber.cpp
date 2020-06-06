#include <vector>

int rob(const std::vector<int>& nums)
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