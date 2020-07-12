#include <iostream>
#include <vector>
using namespace std;

int knapsack(int w, vector<pair<int,int>> bag)
{
    // dp[i][w] = the maximum value with weight w of getting item at i
    vector<vector<int>> dp(bag.size(), vector<int>(w+1));

    for(int i = 0; i <= w; i++)
    {
        for(int item = 0; item < bag.size(); item++)
        {
            int value = bag[item].first;
            int weight = bag[item].second;
            int t1 = item-1 >= 0 ? dp[item-1][i] : 0;
            int t2 = i-weight >= 0 ? value + dp[item][i-weight] : 0;
            dp[item][i] = max(t1, t2);
        }
    }
    return dp[bag.size()-1][w];
}

int main()
{
    vector<pair<int,int>> bag = {{50, 3}, {10, 1}, {120, 5}, {60, 2}};
    cout << knapsack(5, bag) << endl;
}