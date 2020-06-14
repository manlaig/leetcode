#include <vector>
#include <map>

std::vector<int> smallerNumbersThanCurrent(std::vector<int>& nums)
{
    std::map<int, int> occur;
    for(int i : nums)
        occur[i]++;
    
    for(int i = 0; i < nums.size(); i++)
    {
        int total = 0;
        for(std::pair<int, int> p : occur)
            if(p.first >= nums[i])
                break;
            else
                total += p.second;
        nums[i] = total;
    }
    
    return nums;
}

int main()
{

}