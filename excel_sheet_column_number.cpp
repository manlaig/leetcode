#include <string>

int titleToNumber(std::string s)
{
    int total = 0;
    for(int i = s.size() - 1; i >= 0; i--)
        total += std::pow(26, s.size() - i - 1) * (s[i] - 'A' + 1);
    return total;
}

int main()
{
    
}