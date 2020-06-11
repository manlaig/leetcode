#include <vector>

int maxProfit(const std::vector<int>& prices)
{
    if(!prices.size())
        return 0;
    int sum = 0;
    
    for(int i = 1; i < prices.size(); i++)
        if(prices[i] > prices[i-1])
            sum += prices[i] - prices[i-1]; 
    return sum;
}

int main()
{

}