#include <vector>

int maxProduct(std::vector<int>& nums)
{
    if(!nums.size())
        return 0;

    /*
        Since multiplying, we need to keep track of both smallest and largest
        The smallest value can become the largest if multiplied by a negative
        In that case, then update the largest by the smallest * arr[i]
    */

    int l = nums[0];
    int s = nums[0];
    int out = nums[0];
    
    for(int i = 1; i < nums.size(); i++)
    {
        int temp = l;
        l = std::max({ l * nums[i], s * nums[i], nums[i] });
        s = std::min({ temp * nums[i], s * nums[i], nums[i] });
        out = std::max(out, l);
    }
    return out;
}

int main()
{

}