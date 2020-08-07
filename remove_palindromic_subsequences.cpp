#include <string>

int removePalindromeSub(std::string s)
{
    if(!s.size())
        return 0;
    std::string t = s;
    std::reverse(t.begin(), t.end());
    return (t != s) + 1;
}

int main()
{

}