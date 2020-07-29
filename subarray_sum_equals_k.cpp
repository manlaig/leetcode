#include <unordered_map>
#include <vector>

int subarraySum(const std::vector<int>& nums, int k)
{
    std::unordered_map<int, int> lookup;
    lookup[0] = 1;
    
    int sum = 0, out = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        out += lookup[sum-k];
        lookup[sum]++;
    }
    return out;
}

int main()
{

}