#include <unordered_map>
#include <vector>
#include <string>

int longestStrChain(std::vector<std::string>& words)
{
    if(!words.size())
        return 0;
    // dp[i] = length of string chain ending at i
    std::unordered_map<std::string, int> dp;
    dp[words[0]] = 1;
    
    int out = 1;
    for(int i = 1; i < words.size(); i++)
    {
        int most = 0;
        for(int c = 0; c < words[i].size(); c++)
        {
            std::string temp = words[i];
            temp.erase(c,1);
            most = std::max(most, dp[temp] + 1);
        }
        dp[words[i]] = most;
        out = std::max(out, most);
    }
    
    return out;
}

int main()
{

}