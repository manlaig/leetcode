#include <cinttypes>

uint32_t reverseBits(uint32_t n)
{
    int res = 0;
    for(int i = 0; i < 32; i++)
        res |= ((n >> i) & 1) << (31 - i);
    return res;
}

int main()
{

}