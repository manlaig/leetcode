#include <vector>
#include <cmath>

/*
    There are a total of 2^nums.size() subsets of nums
    So, our time and space complexity is O(N * 2^N)

    The Leetcode website doesn't have a more efficient solution either
*/

std::vector<std::vector<int>> subsets(const std::vector<int>& nums)
{
    std::vector<std::vector<int>> out;
    int count = 0;
    int limit = std::pow(2, nums.size());
    while(count < limit)
    {
        std::vector<int> sub;
        int t = count;
        for(int i = 0; i < nums.size(); i++)
        {
            if(t % 2)
                sub.push_back(nums[i]);
            t /= 2;
        }
        out.push_back(sub);
        count++;
    }
    return out;
}

int main()
{
    
}