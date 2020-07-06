#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>

int numDecodings_iter_DP(std::string s)
{
    int n = s.size();
    if(n <= 0)
        return 0;
    std::vector<int> dp(n);
    
    dp[0] = s[0] != '0' ? 1 : 0;
    for(int i = 1; i < n; i++)
    {
        if(s[i] == '0' && (s[i-1] != '1' && s[i-1] != '2'))
            return 0;
        else if(s[i-1] == '2' && s[i] <= '6' || s[i-1] == '1')
        {
            int one = s[i] != '0' ? dp[i-1] : 0;
            int prev = i-2 >= 0 ? dp[i-2] : dp[i-1];
            dp[i] = prev + one;
        }
        else
            dp[i] = dp[i-1];
    }
    return dp[n-1];
}

/*
    This solution uses tree recursion along with dynamic programming
    You can say the solution is O(N) time and O(N) space

    In fact, this solution beat 100% of C++ submissions, in terms of speed.
*/
int helper(const std::string& s, int start, std::unordered_map<int, int>& m)
{
    if(start > s.size())
        return 0;
    else if(m.find(start) != m.end())
        return m[start];
    // we can remove these nested parantheses, but C++ gives warnings then
    else if(start == s.size() || (start == s.size() - 1 && s[start] > '0'))
        return 1;
    else if(s[start] <= '0')
        return 0;
    
    int total = helper(s, start+1, m);
    // we can remove these nested parantheses, but C++ gives warnings then
    if((s[start] == '2' && s[start+1] <= '6') || (s[start] == '1' && s[start+1] <= '9'))
        total += helper(s, start+2, m);
    m[start] = total;
    return total;
}

int numDecodings(std::string s)
{
    std::unordered_map<int,int> m;
    return helper(s, 0, m);
}

int main()
{
    std::cout << numDecodings("12345678910") << std::endl;
    std::cout << numDecodings("10203040") << std::endl;
    std::cout << numDecodings_iter_DP("12345678910") << std::endl;
    std::cout << numDecodings_iter_DP("10203040") << std::endl;
}