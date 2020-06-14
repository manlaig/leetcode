#include <algorithm>
#include <vector>

int findDuplicate(std::vector<int>& nums)
{
    std::sort(nums.begin(), nums.end());
    for(int i = 0, j = 1; j < nums.size(); j++, i++)
        if(nums[i] == nums[j])
            return nums[i];
    return -1;
}

int main()
{

}