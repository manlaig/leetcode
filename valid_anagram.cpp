#include <iostream>
#include <string>
#include <map>

bool isAnagram(std::string s, std::string t)
{
    if(s.size() != t.size())
        return false;
    
    std::map<char, int> freq;
    for(int i = 0; i < s.size(); i++)
    {
        freq[s[i]] = freq.find(s[i]) == freq.end() ? 1 : freq[s[i]] + 1;
        freq[t[i]] = freq.find(t[i]) == freq.end() ? -1 : freq[t[i]] - 1;
    }
    for(std::pair<char, int> p : freq)
        if(p.second != 0)
            return false;
    return true;
}

int main()
{
    
}