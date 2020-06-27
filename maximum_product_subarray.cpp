#include <vector>

int maxProduct(std::vector<int>& nums)
{
    if(!nums.size())
        return 0;
    int l = nums[0];
    int s = nums[0];
    int out = nums[0];
    
    for(int i = 1; i < nums.size(); i++)
    {
        int temp = l;
        l = std::max(std::max(l * nums[i], s * nums[i]), nums[i]);
        s = std::min(std::min(temp * nums[i], s * nums[i]), nums[i]);
        out = std::max(out, l);
    }
    return out;
}

int main()
{

}