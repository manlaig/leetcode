#include <unordered_map>
#include <vector>

int lengthOfLIS(std::vector<int>& nums)
{
    std::unordered_map<int, int> m;
    m[nums.size()-1] = 1;
    int out = 0;
    
    for(int i = nums.size()-1; i >= 0; i--)
    {
        int best = 0;
        for(int j = i; j < nums.size(); j++)
        {
            if(nums[i] < nums[j])
                best = std::max(best, m[j]);
        }
        m[i] = best + 1;
        out = std::max(out, m[i]);
    }
    
    return out;
}

int main()
{

}