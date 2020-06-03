#include <iostream>
#include <map>

/*
    I will soon write a faster algorithm for this problem
    Currently, it's O(n), I just love recursive algorithms that I chose to do it this way
    I used Dynamic Programming, so that's why it's not O(2^n) even though it looks like that.
*/

int climbStairs(int n, std::map<int, int>& m)
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

int main()
{
    std::map<int, int> m;
    std::cout << climbStairs(2, m) << std::endl;
    std::cout << climbStairs(34, m) << std::endl;
    std::cout << climbStairs(45, m) << std::endl;
}