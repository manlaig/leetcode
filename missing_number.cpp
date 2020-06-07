#include <vector>

int missingNumber(const std::vector<int>& nums)
{
    int n = nums.size();
    int max = n * (n+1) / 2;
    int sum = 0;
    for(int i : nums)
        sum += i;
    return max - sum;
}

int main()
{

}
