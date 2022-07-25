#include <vector>

int getStart(const std::vector<int>& arr, int target, int start, int end)
{
    if(start == end && arr[start] == target)
        return start;
    if(start >= end)
        return -1;
    
    int mid = (start - end) / 2 + end;
    if(arr[mid] == target)
    {
        int tmp = getStart(arr, target, start, mid-1);
        return tmp != -1 ? tmp : mid;
    }
    if(arr[mid] < target)
        return getStart(arr, target, mid+1, end);
    return getStart(arr, target, start, mid-1);
}

int getEnd(const std::vector<int>& arr, int target, int start, int end)
{
    if(start == end && arr[start] == target)
        return start;
    if(start >= end)
        return -1;
    
    int mid = (start - end) / 2 + end;
    if(arr[mid] == target)
    {
        int tmp = getEnd(arr, target, mid+1, end);
        return tmp != -1 ? tmp : mid;
    }
    if(arr[mid] < target)
        return getEnd(arr, target, mid+1, end);
    return getEnd(arr, target, start, mid-1);
}

std::vector<int> searchRange(const std::vector<int>& nums, int target)
{
    return { getStart(nums, target, 0, nums.size()-1), getEnd(nums, target, 0, nums.size()-1) };
}

///////////////////////////// Second approach ///////////////////////////////
int binarySearch(const vector<int>& nums, int target, int start, int end)
{
    if(start >= end)
        return -1;
    
    int mid = start + (end - start) / 2;

    if(nums[mid] == target)
        return mid;
    else if(nums[mid] > target)
        return binarySearch(nums, target, start, mid);
    return binarySearch(nums, target, mid + 1, end);
}

vector<int> searchRange2(vector<int>& nums, int target)
{
    if(!nums.size())
        return {-1, -1};
    int index = binarySearch(nums, target, 0, nums.size());
    cout << index << endl;
    if(index == -1)
        return {-1, -1};
    
    int left = index;
    int right = index;
    while(left >= 0 && nums[left] == target)
        left--;
    
    while(right < nums.size() && nums[right] == target)
        right++;
    
    return {left + 1, right - 1};
}
//////////////////////////////////////////////////////////////////////////////z

int main()
{

}