#include <string>

int findLUSlength(const std::string& a, const std::string& b)
{
    if(a.size() != b.size())
        return std::max(a.size(), b.size());
    return a != b ? a.size() : -1;
}

int main()
{

}