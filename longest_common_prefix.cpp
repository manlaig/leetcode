#include <iostream>
#include <string>
#include <vector>
#include <map>

/*
    NOTE: this code was actually judges as a SLOW solution
    From the beginning, I thought of prefix to be same as a substring
    If I had known prefixes correctly, I would've approached the problem differently
*/

bool all_ones(std::vector<int> v)
{
    for(int i : v)
        if(i != 1)
            return false;
    return true;
}

std::string longestCommonPrefix(std::vector<std::string>& strs)
{
    std::map<std::string, std::vector<int> > occur;
    
    for(int i = 0; i < strs.size(); i++)
    {
        for(int end = 0; end < strs[i].size(); end++)
        {
            std::string temp = strs[i].substr(0, end + 1);
            if(occur.find(temp) == occur.end())
            {
                std::vector<int> v(strs.size());
                v[i] = 1;
                occur[temp] = v;
            } else
            {
                occur[temp][i] = 1;
            }
        }
    }
    
    std::string best = "";
    for(std::pair<std::string, std::vector<int> > p : occur)
    {
        if(all_ones(p.second) && p.first.size() > best.size())
            best = p.first;
    }
    return best;
}

int main()
{
    std::vector<std::string> v = {"doga", "car", "racecar"};
    std::cout << longestCommonPrefix(v) << std::endl;
}