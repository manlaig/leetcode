#include <iostream>
#include <vector>

/*
    This is same as the technique called "Two Pointers" by LeetCode
    [1,0,0,1,3]       ->      [1,1,0,0,3]       ->      [1,1,3,0,0]
       ^   i                         ^   i                       ^ i
*/

void moveZeroes(std::vector<int>& nums)
{
    for(int i = 0, next = 0; i < nums.size(); i++)
    {
        // increment next until we find a 0
        if(nums[next] != 0)
            next++;
        else if(nums[i])
        {
            // we know nums[next] == 0
            std::swap(nums[next], nums[i]);
            next++;
        }
    }
}

int main()
{

}