#include <vector>
#include <iostream>
#include <unordered_map>

/*
    I will soon write a faster algorithm for this problem
    Currently, it's O(n), I just love recursive algorithms that I chose to do it this way
    I used Dynamic Programming, so that's why it's not O(2^n) even though it looks like that.
    
    Update: I moved from using maps to unordered_maps, now the algorithm beats 100% of C++ submissions in runtime.
    But, it's terrible in memory usage. So, I'll move to an iterative approach

    Update: I implemented an iterative solution and it's not much different in terms of memory usage.
    I think the call stacks didn't take much memory after all.
*/

int climbStairs(int n, std::unordered_map<int, int>& m)
{
    /*
        This algorithm is currently at both O(n) time and space
        The most efficient algorithm for this is O(logn) time O(1) space
    */
    if(n == 0)
        return 1;
    if(n < 0)
        return 0;
    if(m.find(n) != m.end())
        return m[n];
    m[n] = climbStairs(n-2, m) + climbStairs(n-1, m);
    return m[n];
}

/*
    looks like a fibonacci series, isn't it? I was surprised as well.
*/
int climbStairs_iter(int n)
{
    std::unordered_map<int, int> m;
    m[1] = 1;
    m[2] = 2;

    for(int i = 3; i <= n; i++)
        m[i] = m[i-1] + m[i-2];
    return m[n];    // ways to reach 4 steps
}

int climbStairs_forward_DP(int n)
{
    std::vector<long long> dp(n+3);
    dp[0] = 1LL;
    
    for(int i = 0; i <= n; i++)
    {
        dp[i+1] += dp[i];
        dp[i+2] += dp[i];
    }
    return dp[n];
}

int main()
{
    std::unordered_map<int, int> m;
    std::cout << climbStairs(2, m) << std::endl;
    std::cout << climbStairs(34, m) << std::endl;
    std::cout << climbStairs(45, m) << std::endl;
}