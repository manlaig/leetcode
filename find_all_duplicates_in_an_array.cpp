#include <vector>

/*
    This solution is O(1) space and O(n) time.
    This is a very useful technique for coming up with O(1) space solutions when you are
    given that the array values are 1 <= arr[i] <= arr.size() or something similar.

    This type of solution "jumps" around the array using the element values (since we know their bounds)
    Every iteration we negate the element arr[arr[i]]. This tells us whether we visited this element before or not.
    If arr[i] = 3, then we say arr[3] *= -1; and if arr[3] is already negative, we know we have visited this before.
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