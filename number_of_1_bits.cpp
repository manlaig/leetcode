#include <cinttypes>

/*
    this is very similar to finding a binary representation for a number in base-10
    Time complexity: O(log N)
    Space complexity: O(1)
*/

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