#include <vector>

bool selfDivisible(int num)
{
    int original = num;
    while(num)
    {
        if(num % 10 == 0 || original % (num % 10) != 0)
            return false;
        num /= 10;
    }
    return true;
}

std::vector<int> selfDividingNumbers(int left, int right)
{
    std::vector<int> v;
    for(int i = left; i <= right; i++)
        if(selfDivisible(i))
            v.push_back(i);
    return v;
}

int main()
{

}