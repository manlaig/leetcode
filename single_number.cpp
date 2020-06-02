#include <vector>

// compile with -std=c++11 flag
int singleNumber(std::vector<int>& nums)
{
    int tmp = 0;
    for(int i : nums)
        tmp ^= i;
    return tmp;
}

int main()
{

}