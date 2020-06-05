#include <unordered_map>
#include <vector>
using namespace std;

///////////////// Iterative solution /////////////////

int minCostClimbingStairs(const vector<int>& cost)
{
    // we are given the size of cost is in [2, 1000]
    unordered_map<int, int> m;
    m[0] = 0;
    m[1] = 0;
    for(int i = 2; i <= cost.size(); i++)
        m[i] = min(m[i - 1] + cost[i - 1], m[i - 2] + cost[i - 2]);
    return m[cost.size()];
}

///////////////// Recursive solution /////////////////

int helper(const vector<int>& cost, int so_far, int curr)
{
    if(curr == cost.size() - 1)
        return so_far + cost[curr];
    else if(curr >= cost.size())
        return so_far;
    return min(helper(cost, so_far+cost[curr], curr+1), helper(cost, so_far+cost[curr], curr+2));
}

// I got a weird bug when I tried to use DP for this recursive solution
int minCostClimbingStairs_recur(const vector<int>& cost)
{
    // we are given the size of cost is in [2, 1000]
    if(cost.size() == 2)
        return min(cost[0], cost[1]);
    return min(helper(cost, 0, 0), helper(cost, 0, 1));
}

int main()
{

}