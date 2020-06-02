#include <iostream>
#include <vector>

void helper(std::vector<std::vector<int>>& out, std::vector<int> arr, int start, int end)
{
    if(start >= end)
    {
        out.push_back(arr);
        return;
    }
    for(int i = start; i < end; i++)
    {
        std::swap(arr[i], arr[start]);
        helper(out, arr, start+1, end);
        std::swap(arr[i], arr[start]);
    }
}

std::vector<std::vector<int>> permute(std::vector<int>& nums)
{
    std::vector<std::vector<int>> out;
    helper(out, nums, 0, nums.size());
    return out;
}

int main()
{
    
}