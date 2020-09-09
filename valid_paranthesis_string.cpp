#include <unordered_set>
#include <vector>
#include <string>

bool checkValidString(std::string s)
{
    int bal = 0;
    int stars = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(' || s[i] == '*')
            bal++;
        else if(--bal < 0)
            return false;
    }
    bal = 0;
    for(int i = s.size() - 1; i >= 0; i--)
    {
        if(s[i] == ')' || s[i] == '*')
            bal++;
        else if(--bal < 0)
            return false;
    }
    return bal >= 0;
}

bool checkValidString_DP(std::string s)
{
    if(!s.size())
        return true;
    std::vector<std::unordered_set<int>> dp(s.size());
    
    if(s[0] == '(')
        dp[0].insert(1);
    else if(s[0] == ')')
        return false;
    else if(s[0] == '*')
    {
        dp[0].insert(1);
        dp[0].insert(0);
    }
    
    for(int i = 1; i < s.size(); i++)
    {
        if(s[i] == '(')
        {
            for(int prev : dp[i-1])
            {
                dp[i].insert(prev + 1);
            }
        }
        else if(s[i] == ')')
        {
            for(int prev : dp[i-1])
            {
                if(prev-1 >= 0)
                    dp[i].insert(prev - 1);
            }
        }
        else if(s[i] == '*')
        {
            for(int prev : dp[i-1])
            {
                dp[i].insert(prev + 1);
                dp[i].insert(prev);
                if(prev-1 >= 0)
                    dp[i].insert(prev - 1);
            }
        }
    }
    
    for(int num : dp[s.size()-1])
        if(num == 0)
            return true;
    return false;
}

int main()
{

}