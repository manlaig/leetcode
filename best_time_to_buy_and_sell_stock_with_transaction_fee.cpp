#include <vector>
using namespace std;

int maxProfit(vector<int>& prices, int fee)
{
    // dp[i][0] = max profit if sell on day i
    // dp[i][1] = max profit if buy on day i
    vector<vector<int>> dp(prices.size(), {INT_MIN, 0});

    // the first day has to be a buy
    dp[0][0] = -prices[0] - fee;
    
    for(int i = 1; i < prices.size(); i++)
    {
        dp[i][1] = dp[i-1][1];
        if(dp[i-1][0] + prices[i] > 0)
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]);
        dp[i][0] = max(dp[i-1][0], -prices[i] - fee + dp[i-1][1]);
    }
    
    return dp[prices.size()-1][1];
}

int main()
{

}