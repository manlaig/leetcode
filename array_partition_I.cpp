#include <algorithm>
#include <vector>

int arrayPairSum(std::vector<int>& nums)
{
    std::sort(nums.begin(), nums.end());
    int total = 0;
    for(int i = 0; i < nums.size(); i += 2)
        total += nums[i];
    return total;
}

int main()
{

}