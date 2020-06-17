#include <vector>

/*
    This solution is O(1) space and O(n) time.
    This is a very useful technique for coming up with O(1) space solutions when you are
    given that the array values are 1 <= arr[i] <= arr.size() or something similar
*/

std::vector<int> findDuplicates(std::vector<int>& nums)
{
    std::vector<int> out;
    
    for(int i = 0; i < nums.size(); i++)
    {
        int index = abs(nums[i]) - 1;
        if(nums[index] < 0)
            out.push_back(index+1);
        else
            nums[index] *= -1;
    }
    
    return out;
}

int main()
{

}