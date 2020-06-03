#include <iostream>
#include <string>
#include <vector>
#include <map>

std::string longestCommonPrefix(std::vector<std::string>& strs)
{
    if(!strs.size())
        return "";
    
    bool cont = true;
    std::string prefix = "";
    while(cont)
    {
        if(strs[0].size() <= prefix.size())
            break;
        char s = strs[0][prefix.size()];
        for(int i = 1; i < strs.size(); i++)
        {
            if(strs[i].size() < prefix.size() || strs[i][prefix.size()] != s)
            {
                cont = false;
                break;
            }
        }
        if(cont)
            prefix += s;
    }
    return prefix;
}

int main()
{
    std::vector<std::string> v = {"doga", "dog", "dogracecar"};
    std::cout << longestCommonPrefix(v) << std::endl;
}