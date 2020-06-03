#include <vector>

/*
    I learned this kind of approach from Kadane's algorithm
    But, in this case, we keep an array storing "what's the lowest price UP UNTIL day i"
    It can be either prices[i] OR arr[i-1]
*/

int maxProfit(std::vector<int>& prices)
{
    if(!prices.size())
        return 0;

    int arr[prices.size()];
    arr[0] = prices[0];
    for(int i = 1; i < prices.size(); i++)
        arr[i] = std::min(arr[i-1], prices[i]);
    
    int max = 0;
    for(int i = 0; i < prices.size(); i++)
        if(max < prices[i] - arr[i])
            max = prices[i] - arr[i];
    return max;
}

int main()
{
    
}