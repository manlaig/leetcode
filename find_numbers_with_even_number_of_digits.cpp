#include <vector>

int digitCount(int num)
{
    int count = 0;
    while(num)
    {
        count++;
        num /= 10;
    }
    return count;
}
int findNumbers(const std::vector<int>& nums)
{
    int even = 0;
    for(int num : nums)
        if(digitCount(num) % 2 == 0)
            even++;
    return even;
}

int main()
{

}