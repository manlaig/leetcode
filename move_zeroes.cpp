#include <iostream>
#include <vector>

void moveZeroes(std::vector<int>& nums)
{
    for(int i = 0, next = 0; i < nums.size(); i++)
    {
        if(nums[next] != 0)
            next++;
        else if(nums[i])
        {
            std::swap(nums[next], nums[i]);
            next++;
        }
    }
}

int main()
{

}