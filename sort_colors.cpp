#include <vector>

void sortColors(std::vector<int>& nums)
{
    int next = 0;
    for(int i = 1; i < nums.size(); i++)
    {
        if(next < nums.size() && nums[next] == 0)
            next++;
        if(nums[i] == 0 && next < nums.size())
            std::swap(nums[next++], nums[i]);
    }
    if(next >= nums.size())
        next = 0;
    for(int i = next+1; i < nums.size(); i++)
    {
        if(next < nums.size() && nums[next] == 1)
            next++;
        if(nums[i] == 1 && next < nums.size() && nums[next] != 1)
            std::swap(nums[next++], nums[i]);
    }
}

int main()
{

}