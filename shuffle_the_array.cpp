#include <vector>

std::vector<int> shuffle(std::vector<int>& nums, int n)
{
    std::vector<int> out;
    out.reserve(2*n);
    for(int i = 0; i < n; i++)
    {
        out.push_back(nums[i]);
        out.push_back(nums[i+n]);
    }
    return out;
}

int main()
{

}