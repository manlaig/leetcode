#include <vector>

void rotate(std::vector<int>& nums, int k)
{
    std::vector<int> arr(nums.size());
    for(int i = 0; i < nums.size(); i++)
    {
        int new_index = (i + k) % nums.size();
        arr[new_index] = nums[i];
    }
    nums = arr;
}

int main()
{
    
}