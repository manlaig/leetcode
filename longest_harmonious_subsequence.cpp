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

// slower solution I implemented after a while since my first implementation
struct Sequence
{
    int size;
    int max;
    int min;
    
    Sequence() : size(0), max(INT_MIN), min(INT_MAX) {}
};

int findLHS_slow(const std::vector<int>& nums)
{
    // dp[num].first = length of sequence for num+1
    // dp[num].second = length of sequence for num-1
    std::unordered_map<int, std::pair<Sequence, Sequence>> dp;
    int out = 0;
    for(int num : nums)
    {
        auto& seq = dp[num];
        seq.first.size++;
        seq.first.max = std::max(seq.first.max, num);
        seq.first.min = std::min(seq.first.min, num);
        seq.second.size++;
        seq.second.max = std::max(seq.second.max, num);
        seq.second.min = std::min(seq.second.min, num);
        
        auto& seq2 = dp[num-1];
        seq2.first.size++;
        seq2.first.max = std::max(seq2.first.max, num);
        seq2.first.min = std::min(seq2.first.min, num);
        
        auto& seq3 = dp[num+1];
        seq3.second.size++;
        seq3.second.max = std::max(seq3.second.max, num);
        seq3.second.min = std::min(seq3.second.min, num);

        if(seq.first.max != seq.first.min)
            out = std::max(out, seq.first.size);
        if(seq.second.max != seq.second.min)
            out = std::max(out, seq.second.size);
        if(seq2.first.max != seq2.first.min)
            out = std::max(out, seq2.first.size);
        if(seq3.second.max != seq3.second.min)
            out = std::max(out, seq3.second.size);
    }
    return out;
}

int main()
{

}