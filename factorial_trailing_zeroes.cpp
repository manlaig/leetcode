#include <cmath>

int trailingZeroes(int n)
{
    if(n == 0)
        return 0;
    int mult = n < 0 ? -1 : 1;
    n = n * mult;
    int total = 0;
    int t = std::pow(5, (int) (std::log(n) / std::log(5)));
    while(t > 1)
    {
        total += n / t;
        t /= 5;
    }
    return total * mult;
}

int main()
{
    
}