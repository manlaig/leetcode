#include <algorithm>
#include <vector>

int findKthLargest(const std::vector<int>& nums, int k)
{
    if(k <= 0 || k > nums.size())
        return -1;
    std::sort(nums.begin(), nums.end(), [](int a, int b) { return a > b; });
    return nums[k-1];
}

int main()
{

}