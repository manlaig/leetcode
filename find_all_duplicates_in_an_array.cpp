#include <vector>

std::vector<int> findDuplicates(std::vector<int>& nums)
{
    std::vector<int> out;
    
    for(int i = 0; i < nums.size(); i++)
    {
        int index = abs(nums[i]) - 1;
        if(nums[index] < 0)
            out.push_back(index+1);
        else
            nums[index] *= -1;
    }
    
    return out;
}

int main()
{

}