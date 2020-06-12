#include <vector>

std::vector<int> productExceptSelf(const std::vector<int>& nums)
{
    const int n = nums.size();
    std::vector<int> pre(n), sub(n);
    sub[n-1] = 1;
    pre[0] = 1;
    
    for(int i = 1; i < n; i++)
        pre[i] = pre[i-1] * nums[i-1];
    for(int i = n-2; i >= 0; i--)
        sub[i] = sub[i+1] * nums[i+1];
    
    std::vector<int> out(n);
    out[0] = sub[0];
    out[n-1] = pre[n-1];
    for(int i = 1; i < n-1; i++)
    {
        out[i] = sub[i] * pre[i];
    }
    return out;
}

int main()
{

}