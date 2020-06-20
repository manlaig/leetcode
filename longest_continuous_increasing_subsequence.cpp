#include <vector>

int findLengthOfLCIS(std::vector<int>& nums)
{
    if(!nums.size())
        return 0;
    int last = nums[0];
    int count = 1;
    int out = 1;
    for(int i = 1; i < nums.size(); i++)
    {
        if(nums[i] > last)
        {
            last = nums[i];
            count++;
        }
        else
        {
            out = std::max(count, out);
            count = 1;
            last = nums[i];
        }
    }
    return std::max(out, count);
}

int main()
{

}