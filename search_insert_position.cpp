#include <iostream>
#include <vector>

int helper(std::vector<int>& arr, int target, int start, int end)
{
    if(start >= end)
        return start;
    int mid = (start + end) / 2;
    if(arr[mid] == target)
        return mid;
    else if(arr[mid] > target)
        return helper(arr, target, start, mid);
    else
        return helper(arr, target, mid+1, end);
}

int searchInsert(std::vector<int>& nums, int target) {
    return helper(nums, target, 0, nums.size());
}

int main()
{

}