#include <unordered_map>
#include <vector>

int findLHS(const std::vector<int>& nums)
{
    std::unordered_map<int, int> occur;
    for(int i : nums)
        occur[i] = occur.find(i) == occur.end() ? 1 : occur[i] + 1;
    
    int most = 0;
    for(int i : nums)
    {
        int up = (occur.find(i+1) != occur.end() ? occur[i+1] : 0);
        int down = (occur.find(i-1) != occur.end() ? occur[i-1] : 0);
        if(std::max(up,down) > 0)
            most = std::max(most, occur[i] + std::max(up, down));
        // LeetCode test don't allow size-1 arrays
        if(most == 1)
            most = 0;
    }
    return most;
}

int main()
{

}