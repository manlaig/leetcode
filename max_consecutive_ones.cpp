#include <vector>

int findMaxConsecutiveOnes(std::vector<int>& nums)
{
    int add = 0;
    int max = 0;
    for(int i : nums)
        if(i == 1)
            add++;
        else
        {
            max = std::max(max, add);
            add = 0;
        }
    return std::max(max, add);
}

int main()
{

}