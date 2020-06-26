#include <vector>

int findMin(std::vector<int>& nums)
{
    if(!nums.size())
        return 0;
    int start = 0;
    int end = nums.size()-1;
    
    while(start < end)
    {
        int mid = (start+end) / 2;
        int left = mid-1 >= 0 ? nums[mid-1] : INT_MAX;
        int right = mid+1 > end ? INT_MAX : nums[mid+1];
        if(nums[mid] < left && nums[mid] < right)
            return nums[mid];
        else if(nums[mid] > nums[end])
            start = mid + 1;
        else
            end = mid - 1;
    }
    return nums[start];
}

int main()
{

}