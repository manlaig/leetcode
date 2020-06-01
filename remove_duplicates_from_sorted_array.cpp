#include <iostream>
#include <vector>

/*
    Compile with -std=c++11 flag
*/

int removeDuplicates(std::vector<int>& nums)
{
    bool init = false;
    int next = nums.size();
    int last = -1;
    for(int i = 1; i < nums.size(); i++)
    {
        if(!init && nums[i] == nums[i-1])
        {
            init = true;
            last = nums[i];
            next = i;
        }
        else if(init && nums[i] > last)
        {
            last = nums[i];
            std::swap(nums[i], nums[next]);
            next++;
        }
    }
    return next;
}

int main()
{
    std::vector<int> v = {0,0,1,1,1,2,3,3};
    removeDuplicates(v);
    for(int i : v)
        std::cout << i << ' ';
    std::cout << std::endl;
}