#include <cinttypes>

int hammingWeight(uint32_t n)
{
    int total = 0;
    while(n)
    {
        if(n % 2)
            total += 1;
        n /= 2;
    }
    return total;
}

int main()
{
    
}