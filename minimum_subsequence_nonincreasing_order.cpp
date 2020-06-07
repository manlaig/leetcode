#include <algorithm>
#include <vector>

// compile with c++11
std::vector<int> minSubsequence(std::vector<int>& nums)
{
    std::sort(nums.begin(), nums.end(), [](int a, int b) { return a > b; });
    
    int total = 0;
    for(int i : nums)
        total += i;   
    
    int end = 0;
    int so_far = nums[0];
    while(total - nums[end] >= so_far)
    {
        total -= nums[end++];
        so_far += nums[end];
    }
    std::vector<int> out(end+1);
    for(int i = 0; i <= end; i++)
        out[i] = nums[i];
    return out;
}

int main()
{

}