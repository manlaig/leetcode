#include <vector>

/*
    We are given the information that values in the array are 1 <= a[i] <= nums.size()
    So, we can use the VALUE of a[i] to index the array and mark which numbers are present
    The INDEXES that hasn't been marked are the numbers that are missing
*/

std::vector<int> findDisappearedNumbers(std::vector<int>& nums)
{
    std::vector<int> out;
    for(int i = 0; i < nums.size(); i++)
        nums[std::abs(nums[i]) - 1] = -1 * std::abs(nums[std::abs(nums[i]) - 1]);
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] >= 0)
            out.push_back(i+1);
    }
    return out;
}

int main()
{

}