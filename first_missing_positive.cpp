#include <vector>

/*
    An important observation here is that numbers <= 0 and
    numbers > nums.size() are useless

    If we get rid of them, the problem converts to finding
    the missing number in an array with elements in the 
    range [1, nums.size()], which there's a question like that
    in leetcode already that solves it in place in O(n)
*/
int firstMissingPositive(std::vector<int>& nums)
{
    for(int& num : nums)
        if(num <= 0 || num > nums.size())
            num = INT_MAX;
    
    for(int i = 0; i < nums.size(); i++)
    {
        if(abs(nums[i]) != INT_MAX)
        {
            if(nums[abs(nums[i])-1] > 0)
                nums[abs(nums[i])-1] *= -1;
        }
    }
    for(int i = 0; i < nums.size(); i++)
        if(nums[i] > 0)
            return i+1;
    return nums.size()+1;
}

int main()
{

}