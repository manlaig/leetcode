#include <iostream>
#include <cmath>
#include <set>

bool isHappy(int n)
{
    std::set<int> seen;
    int total = n;
    while(total != 1)
    {
        int t = total;
        total = 0;

        while(t)
        {
            total += std::pow(t % 10, 2);
            t /= 10;
        }
        if(seen.find(total) != seen.end())
            return false;
        seen.insert(total);
    }
    return true;
}

int main()
{
    std::cout << isHappy(1234) << std::endl;
}