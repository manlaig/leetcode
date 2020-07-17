#include <vector>

int search(std::vector<int>& nums, int target)
{
    int low = 0;
    int high = nums.size()-1;
    
    while(low <= high)
    {
        int mid = (low+high) / 2;
        
        if(nums[mid] == target)
            return mid;
        else if(nums[low] > nums[high])
        {
            // rotated
            if(nums[mid] > nums[low] && target > nums[mid])
                low = mid+1;
            else if(nums[mid] > nums[low] && target >= nums[low])
                high = mid-1;
            else if(nums[mid] < nums[low] && target >= nums[low])
                high = mid-1;
            else if(nums[mid] < nums[low] && target < nums[mid])
                high = mid-1;
            else
                low = mid+1;
        }
        else
        {
            // not rotated
            if(nums[mid] > target)
                high = mid-1;
            else
                low = mid+1;
        }
    }
    return -1;
}

int main()
{

}