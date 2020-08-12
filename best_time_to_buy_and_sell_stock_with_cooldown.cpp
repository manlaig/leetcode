#include <vector>
using namespace std;

int maxProfit(vector<int>& prices)
{
    if(!prices.size())
        return 0;
    vector<int> sell(prices.size());
    vector<int> buy(prices.size());
    vector<int> wait(prices.size());
    buy[0] = -prices[0];
    
    // on day i, we can either buy, sell, or wait (cooldown)
    for(int i = 1; i < prices.size(); i++)
    {
        buy[i] = max(buy[i-1], wait[i-1] - prices[i]);
        sell[i] = prices[i] > prices[i-1] ? buy[i-1] + prices[i] : sell[i-1];
        wait[i] = max({sell[i-1], buy[i-1], wait[i-1]});
    }
    
    int n = prices.size()-1;
    return max({sell[n], buy[n], wait[n]});
}

int main()
{

}