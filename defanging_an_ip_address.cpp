#include <string>

std::string defangIPaddr(std::string address)
{
    std::string out;
    for(char c : address)
    {
        if(c == '.')
            out += "[.]";
        else
            out += c;
    }
    return out;
}

int main()
{
    
}