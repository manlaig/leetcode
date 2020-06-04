#include <vector>
#include <map>

bool containsNearbyDuplicate(std::vector<int>& nums, int k)
{
    std::map<int, int> m;
    for(int i = 0; i < nums.size(); i++)
    {
        if(m.find(nums[i]) != m.end() && std::abs(m[nums[i]] - i) <= k)
            return true;
        else
            m[nums[i]] = i;
    }
    return false;
}

int main()
{
    
}