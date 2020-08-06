#include <algorithm>
#include <vector>

void helper(int low, int high, std::vector<int>& out, int curr)
{
    if(curr >= low && curr <= high)
        out.push_back(curr);
    if(curr % 10 != 9)
        helper(low, high, out, curr * 10 + (curr % 10 + 1));
}

std::vector<int> sequentialDigits(int low, int high)
{
    std::vector<int> out;
    for(int i = 1; i < 10; i++)
        helper(low, high, out, i);
    std::sort(out.begin(), out.end());
    return out;
}

int main()
{

}