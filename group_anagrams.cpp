#include <unordered_map>
#include <string>
#include <vector>

bool isAnagram(std::string s1, std::string s2)
{
    if(s1.size() != s2.size())
        return false;
    std::unordered_map<char, int> occur;
    for(int i = 0; i < s1.size(); i++)
    {
        occur[s1[i]]++;
        occur[s2[i]]--;
    }
    for(auto p : occur)
        if(p.second != 0)
            return false;
    return true;
}

std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string>& strs)
{
    std::vector<std::vector<std::string>> out;
    
    for(int i = 0; i < strs.size(); i++)
    {
        bool found = false;
        for(std::vector<std::string>& elem : out)
        {
            if(isAnagram(elem[0], strs[i]))
            {
                found = true;
                elem.push_back(strs[i]);
                break;
            }
        }
        if(!found)
            out.push_back({strs[i]});
        
    }
    return out;
}

int main()
{

}