#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// a different way of doing DP, somehow it's slower that the other iterative DP solution
// which I think is very weird since both are very similar
int coinChange_forward_DP(vector<int>& coins, long long amount)
{
    if(!amount)
        return 0;
    if(!coins.size() || amount < 0)
        return -1;
    vector<int> dp(amount+1);

    // initialize which amounts can be changed by the coins
    for(int coin : coins)
        if(coin <= amount)
            dp[coin]++;

    for(int i = 1; i <= amount; i++)
    {
        // if it can be changed by the coins
        if(dp[i])
        {
            // leetcode has a stupid test case with INT_MAX, so I cast it to int64
            for(long long coin : coins)
            {
                coin += i;
                if(coin <= amount)
                    dp[coin] = min(dp[coin] ? dp[coin] : INT_MAX, 1 + dp[i]);
            }
        }
    }
    return dp[amount] ? dp[amount] : -1;
}

// A much faster algorithm compared to the below other ones
int coinChange_iter_DP(vector<int>& coins, int amount)
{
    int dp[amount+1];
    dp[0] = 0;
    
    for(int i = 1; i <= amount; i++)
    {
        dp[i] = 0;
        int count = INT_MAX;
        for(int val : coins)
        {
            if(i - val >= 0 && dp[i - val] != -1)
                count = min(dp[i - val], count);
        }
        dp[i] = count == INT_MAX ? -1 : count+1;
    }
    return dp[amount];
}

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
                // count holds the number of changes we made so far4 
                dp[i] = count + dp[left];
                left = 0;   // cuz of the if(left) below
                break;
            }
            
            if(left == 0)
            {
                dp[i] = count;
                break;
            }
            else if(coins[j] <= left && coins[j] > 0)
            {
                count++;
                left -= coins[j];
            }
            else
            // decrement if we can't use coins[j] anymore, cuz coins[j] > left
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