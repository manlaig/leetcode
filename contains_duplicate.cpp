#include <algorithm>
#include <vector>

/*
    1. In C++, sets and maps are implemented using balanced trees,
    so if we use them the solution will have O(NlogN) time and O(N) space
    2. By having a fixed-size array, we can have a O(N) time and O(N) space solution
    3. We can also sort them, then check of duplicates, which is O(NlogN) time and O(1) space
    
*/
bool containsDuplicate(std::vector<int>& nums)
{
    if(nums.size() <= 1)
        return false;
    std::sort(nums.begin(), nums.end());
    for(int i = 1; i < nums.size(); i++)
        if(nums[i] == nums[i-1])
            return true;
    return false;
}

int main()
{

}