#include <iostream>
#include <map>

/*
    I will soon write a faster algorithm for this problem
    Currently, it's O(2^n), I just love recursive algorithms that I chose to do it this way
*/

int helper(int n, std::map<int, int>& m)
{
    if(n == 0)
        return 1;
    if(n < 0)
        return 0;
    if(m.find(n) != m.end())
        return m[n];
    m[n] = helper(n-1, m) + helper(n-2, m);
    return m[n];
}

int climbStairs(int n)
{
    std::map<int, int> m;
    return helper(n, m);
}

int main()
{
    std::cout << climbStairs(2) << std::endl;
    std::cout << climbStairs(34) << std::endl;
    std::cout << climbStairs(45) << std::endl;
}