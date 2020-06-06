#include <vector>

int helper(const std::vector<int>& nums, int start = 0, int end = 0)
{
    if(start >= end)
        return nums[start];
    int mid = (start + end) / 2;
    int t1 = helper(nums, start, mid-1);
    int t2 = helper(nums, mid+1, end);
    if(t1 == t2)
    {
        return t1;
    }
    // 2223 3333
    int count_t1 = 0;
    int count_t2 = 0;
    for(int i = 0; i <= end; i++)
    {
        count_t1 += (nums[i] == t1 ? 1 : -1);
        count_t2 += (nums[i] == t2 ? 1 : -1);
    }
    return count_t1 > count_t2 ? t1 : t2;
}

/*
    The most straightforward approach here is to use a hash map
    But, I want to experiment with approaches using O(1) space but with same time complexity
*/
// divide and conquer O(nlogn) time algorithm by using O(logn) space
int majorityElement_recur(const std::vector<int>& nums)
{
    if(!nums.size())
        return 0;
    return helper(nums, 0, nums.size()-1);
}

// Boyer-Moore voting algorithm
int majorityElement(const std::vector<int>& nums)
{
    if(!nums.size())
        return -1;
    int out = nums[0];
    int count = 1;
    for(int i = 1; i < nums.size(); i++)
    {
        if(!count)
            out = nums[i];
        count += (out == nums[i]) ? 1 : -1;
    }
    return out;
}

int main()
{

}