#include <unordered_map>
#include <string>
#include <vector>

// this solution uses the fact that 2 anagrams are the same string when they are sorted
// we use std::move(), which makes the function so much faster,
// in fact it beat 95% in time and 90% in space
std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs)
{
    std::unordered_map<std::string, std::vector<std::string>> m;
    
    for(const std::string& str : strs)
    {
        std::string sorted = str;
        std::sort(sorted.begin(), sorted.end());
        m[sorted].push_back(str);
    }
    
    int i = 0;
    std::vector<std::vector<std::string>> out(m.size());
    for(auto it = m.begin(); it != m.end(); it++)
        out[i++] = std::move(it->second);    // to avoid copying
    
    return out;
}

////////////////////////////// SLOWER SOLUTION //////////////////////////////
// time limit exceeded :(
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