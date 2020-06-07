#include <vector>

int maxProduct(const std::vector<int>& nums)
{
    int first = std::max(nums[0], nums[1]);
    int second = std::min(nums[0], nums[1]);
    
    for(int i = 2; i < nums.size(); i++)
    {
        if(nums[i] >= first)
        {
            second = first;
            first = nums[i];
        }
        else if(nums[i] > second)
            second = nums[i];
    }
    return (first-1) * (second-1);
}

int main()
{
    
}