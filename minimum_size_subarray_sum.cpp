#include <vector>

int minSubArrayLen(int s, std::vector<int>& nums)
{
    int front = 0;
    int back = 0;
    int sum = 0;
    int out = INT_MAX;
    while(front < nums.size() && back <= front)
    {
        if(sum < s)
            sum += nums[front++];
        else
        {
            out = std::min(out, front-back);
            sum -= nums[back++];
        }
    }
    while(sum >= s)
    {
        out = std::min(out, front-back);
        sum -= nums[back++];
    }
    return out == INT_MAX ? 0 : out;
}

int main()
{

}