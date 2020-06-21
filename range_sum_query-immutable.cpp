#include <vector>

class NumArray
{
    std::vector<int> sums;
public:
    NumArray(const std::vector<int>& nums)
    {
        sums.reserve(nums.size());
        for(int i = 0; i < nums.size(); i++)
            sums.push_back(nums[i] + (i > 0 ? sums[i-1] : 0));
    }
    
    int sumRange(int i, int j)
    {
        if(j >= sums.size())
            return 0;
        return sums[j] - (i-1 >= 0 ? sums[i-1] : 0);
    }
};

int main()
{
    
}