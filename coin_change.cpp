#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int coinChange(vector<int>& coins, int amount)
{
    unordered_map<int,int> dp;
    
    sort(coins.begin(), coins.end());
    for(int i = 0; i <= amount; i++)
    {
        int left = i;
        int count = 0;
        for(int j = coins.size() - 1; j >= 0;)
        {
            if(dp.find(left) != dp.end() && dp[left] != -1)
            {
                dp[i] = count + dp[left];
                left = 0;
                break;
            }
            
            if(left == 0)
            {
                dp[i] = count;
                break;
            }
            else if(coins[j] <= left && left - coins[j] >= 0 && coins[j] > 0)
            {
                count++;
                left -= coins[j];
            }
            else
                j--;
        }
        if(left)
            dp[i] = -1;
    }
    return dp[amount];
}


int helper(unordered_map<int, int>& dp, vector<int>& coins, int amount)
{
    if(amount < 0)
        return -1;
    if(amount == 0)
        return 0;
    if(dp.find(amount) != dp.end())
        return dp[amount];

    int min = INT_MAX;
    for(int i = 0; i < coins.size(); i++)
    {
        int t = helper(dp, coins, amount - coins[i]);
        if(t < min && t != -1)
            min = t + 1;
    }
    dp[amount] = min == INT_MAX ? -1 : min;
    return dp[amount];
}

int coinChange_recur(vector<int>& coins, int amount)
{
    unordered_map<int, int> dp;
    return helper(dp, coins, amount);
}

int main()
{
    vector<int> coins = {3,7,13,17};
    for(int i = 1; i <= 100; i++)
    {
        cout << coinChange(coins, i) << " " << coinChange_recur(coins, i) << endl;
    }
}