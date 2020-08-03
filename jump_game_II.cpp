#include <vector>

/*
    At i = 0, end is nums[0], when end = nums[nums[0]],
    bound will be the farthest possible reach between
    i = 0 and i = nums[0]
*/

int jump(const std::vector<int>& nums)
{
    if(nums.size() == 1)
        return 0;
    int bound = 0, count = 0, end = 0;
    
    for(int i = 0; i < nums.size(); i++)
    {
        bound = std::max(i+nums[i], bound);
        
        if(bound >= nums.size()-1)
            return count+1;
        
        if(i == end)
        {
            end = bound;
            count++;
        }
    }
    return count;
}

int main()
{

}