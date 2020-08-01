#include <unordered_map>
#include <vector>

/*
    The idea behind this approach is that if we have an array
    containing sum of all elements up to i, then a continuous
    subarray with sum k ending at index j means it has a difference
    of k between index i and j in the array of sums. 
*/
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