#include <vector>
using namespace std;

int change(int amount, vector<int>& coins)
{
    if(!amount)
        return 1;
    if(!coins.size())
        return 0;
    
    // dp[5][2] = number of unique ways of changing 5 by using the first 3 coins
    vector<vector<int>> dp(amount+1, vector<int>(coins.size()));
    for(int coin = 0; coin < coins.size(); coin++)
        dp[0][coin] = 1;
    
    for(int i = 1; i <= amount; i++)
    {
        for(int coin = 0; coin < coins.size(); coin++)
        {
            int t = coin-1 < 0 ? 0 : dp[i][coin-1];
            if(i - coins[coin] >= 0)
                dp[i][coin] = dp[i-coins[coin]][coin] + t;
            else
                dp[i][coin] = t;
        }
    }
    
    return dp[amount][coins.size()-1];
}

int main()
{

}