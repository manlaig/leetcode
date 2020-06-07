#include <string>

/*
    This solution is very similar to Eudlid's GCD algorithm for numbers
*/

std::string modulo(const std::string& s1, const std::string& s2)
{
    int i;
    for(i = 0; i + s2.size() <= s1.size(); i += s2.size())
        if(s1[i] != s2[i % s2.size()])
            return s1.substr(i, s1.size() - i);
    return s1.substr(i, s1.size() - i);
}

std::string gcdOfstd::Strings(std::string str1, std::string str2)
{
    if(str2.size() > str1.size())
    {
        std::string temp = str1;
        str1 = str2;
        str2 = temp;
    }
    
    if(str2 == "")
        return str1;
    
    int n1 = str1.size();
    int n2 = str2.size();
    
    std::string rem = modulo(str1, str2);
    if(rem == str1)
        return "";
    return gcdOfstd::Strings(str2, rem);
}

int main()
{

}