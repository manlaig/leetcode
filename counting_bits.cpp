#include <vector>
#include <cmath>

std::vector<int> countBits(int num)
{
    if(num < 0)
        return {0};
    std::vector<int> out(num+1);
    out[0] = 0;
    for(int i = 1; i <= num; i++)
    {
        // clearing the most significant 1
        int mask = ~(1 << ((int)std::log2(i)));
        out[i] = 1 + out[i & mask];
    }
    return out;
}

int main()
{

}