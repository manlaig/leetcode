#include <unordered_map>
#include <vector>

int longestArithSeqLength(const std::vector<int>& A)
{
    // for each number, we store the last number in the sequence and the length of the sequence
    std::unordered_map<int, int> dp[A.size()];
    
    int best = 2;
    for(int i = 1; i < A.size(); i++)
    {
        for(int j = 0; j < i; j++)
        {
            for(std::pair<int, int> p : dp[j])
            {
                // p.first is the difference
                if(A[i] - A[j] == p.first)
                {
                    dp[i][p.first] = p.second + 1;
                    best = std::max(best, p.second + 1);
                }
            }
            if(dp[i].find(A[i] - A[j]) == dp[i].end())
                dp[i][A[i] - A[j]] = 2;
        }
    }
        
    return best;
}

int main()
{

}