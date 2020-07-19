#include <string>
#include <vector>

int numSub(std::string s)
{
    std::vector<int> dp(s.size());
    
    int sum = 0;
    for(int i = s.size()-1; i >= 0; i--)
    {
        if(s[i] == '1')
        {
            dp[i] = (i+1 < s.size() ? dp[i+1] : 0) + (s[i] - '0');
            sum = (sum + dp[i]) % ((int)1e9+7);
        }
    }
    return sum;
}

int main()
{
    
}