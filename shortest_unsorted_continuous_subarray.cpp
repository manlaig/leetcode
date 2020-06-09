#include <vector>

int findUnsortedSubarray(std::vector<int>& nums)
{
    int n = nums.size();
    if(!n)  return 0;
    
    int small[n];       // smallest value down until index i
    int big[n];         // biggest value up to index i
    
    small[n-1] = nums[n-1];
    big[0] = nums[0];
    
    for(int i = n - 2; i >= 0; i--)
    {
        small[i] = std::min(small[i+1], nums[i]);
        int j = n - i - 1;
        big[j] = std::max(big[j-1], nums[j]);
    }
    
    int start = 0;
    while(start < n && small[start] == nums[start])
        start++;
    
    int end = n - 1;
    while(end >= 0 && big[end] == nums[end])
        end--;
    
    return end <= start ? 0 : end - start + 1;
}

int main()
{

}