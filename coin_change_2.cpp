#include <vector>
using namespace std;

int change_1D(int amount, const vector<int>& coins)
{
    vector<int> dp(amount+1);
    dp[0] = 1;

    // the order of the loops matter here    
    for(int j = 0; j < coins.size(); j++)
        for(int i = 1; i <= amount; i++)
            dp[i] = (i-coins[j] >= 0 ? dp[i-coins[j]] : 0) + (j>0 ? dp[i] : 0);

    return dp[amount];
}

int change_2D(int amount, const vector<int>& coins)
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
            // # of ways to change without using coins[coin]
            // if coin = 0, then you can't change with an empty set
            // in that case, # of ways is 0 otherwise dp[i][coin-1]
            int not_choose = coin == 0 ? 0 : dp[i][coin-1];
            if(i - coins[coin] >= 0)
            // you can change using the current coin or by skipping it
                dp[i][coin] = dp[i-coins[coin]][coin] + not_choose;
            else
                dp[i][coin] = not_choose;
        }
    }
    
    // # of ways of changing 'amount' by using first coins.size() coins
    return dp[amount][coins.size()-1];
}

int main()
{

}