#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int>& nums)
{
    /*
        1432 -> 2431 -> 2134
    */
    if(nums.size() <= 1)
        return;
    
    int i = nums.size()-2;
    while(i >= 0 && nums[i] >= nums[i+1])
        i--;
    
    if(i < 0)
    {
        reverse(nums.begin(), nums.end());
    }
    else
    {
        int smallest = -1;
        int ref = nums[i];
        for(int val = i; val < nums.size(); val++)
        {
            if(nums[val] > ref)
            {
                if(smallest == -1 || nums[val] <= nums[smallest])
                    smallest = val;
            }
        }
        if(smallest != -1)
        {
            swap(nums[i], nums[smallest]);
            reverse(nums.begin()+i+1, nums.end());
        }
    }
}

int main()
{

}