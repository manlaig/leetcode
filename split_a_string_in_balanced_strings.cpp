#include <string>

int balancedStringSplit(const std::string& s)
{
    int count = 0;
    int out = -1;
    for(const char& c : s)
    {
        if(count == 0)
            out++;
        count += (c == 'L') ? -1 : 1;
    }
    return count == 0 ? out + 1 : out;
}

int main()
{

}