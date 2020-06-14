#include <vector>

std::vector<int> decompressRLElist(const std::vector<int>& nums)
{
    std::vector<int> out;
    if(nums.size() % 2)
        return out;
    
    for(int i = 1; i < nums.size(); i += 2)
        for(int j = 0; j < nums[i-1]; j++)
            out.push_back(nums[i]);
    return out;
}

int main()
{

}