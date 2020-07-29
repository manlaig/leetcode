#include <vector>

bool helper(const std::vector<int>& nums, int target, int low, int high)
{
    if(low > high)
        return false;
    
    int mid = (low + high) / 2;
    
    if(nums[mid] == target)
        return true;
    
    if(nums[mid] == nums[high] && nums[mid] == nums[low])
    {
        return helper(nums, target, low, mid-1) || helper(nums, target, mid+1, high);
    }
    else if(nums[mid] < target)
    {
        // 4 5 1 2 3
        if(nums[low] > nums[mid] && nums[low] <= target)
            high = mid-1;
        else
            low = mid+1;
    }
    else
    {
        // 4 5 6 1 2
        if(nums[high] < nums[mid] && nums[high] >= target)
            low = mid+1;
        else
            high = mid-1;
    }
    return helper(nums, target, low, high);
}
bool search(std::vector<int>& nums, int target)
{   
    return helper(nums, target, 0, nums.size()-1);
}

int main()
{

}