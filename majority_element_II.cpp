#include <vector>

std::vector<int> majorityElement(std::vector<int>& nums)
{
    bool init1 = false, init2 = false;
    int n1 = 0, n2 = 0;
    int count1 = 0, count2 = 0;
    
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] == n1 && init1)
        {
            count1++;
        }
        else if(nums[i] == n2 && init2)
        {
            count2++;
        }
        else if(count1 <= 0)
        {
            init1 = true;
            n1 = nums[i];
            count1 = 1;
        }
        else if(count2 <= 0)
        {
            init2 = true;
            n2 = nums[i];
            count2 = 1;
        }
        else
        {
            count1--;
            count2--;
        }
    }
    
    count1 = 0;
    count2 = 0;
    std::vector<int> out;
    
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] == n1)
            count1++;
        else if(nums[i] == n2)
            count2++;
    }

    if(count1 > nums.size() / 3)
        out.push_back(n1);
    if(count2 > nums.size() / 3)
        out.push_back(n2);
    
    return out;
}

int main()
{

}