#include <unordered_map>
using namespace std;

int helper(long long n, unordered_map<long long, int>& dp)
{
    if(n == 1)
        return 0;
    if(n <= 0)
        return 0;
    if(dp[n])
        return dp[n];
    if(n % 2 == 0)
    {
        dp[n] = helper(n/2, dp)+1;
        return dp[n];
    }
    dp[n] = min(helper(n+1LL, dp), helper(n-1, dp))+1;
    return dp[n];
}

int integerReplacement(long long n)
{
    if(n == 0)
        return 1;
    unordered_map<long long, int> dp;
    return helper(n, dp);
}

int main()
{

}