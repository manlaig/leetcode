#include <vector>

bool checkPossibility(const std::vector<int>& nums)
{
    if(nums.size() <= 2)
    {
        return true;
    }
    // editing allowed at most 1
    bool del = false;
    for(int i = 0; i < nums.size()-1; i++)
    {
        if(i+2 < nums.size() && std::min(nums[i], nums[i+1]) > nums[i+2])
        {
            if(nums[i] > nums[i+1])
            {
                // 5 3 1
                return false;
            }
            else
            {
                // 5 6 4 -> 5 6 6
                if(del)
                    return false;
                nums[i+2] = nums[i+1];
                del = true;
            }
        }
        if(nums[i] > nums[i+1])
        {
            // 1 5 3 -> 1 1 3
            if(del)
                return false;
            del = true;
        }
    }
    return true;
}

int main()
{

}
