#include <unordered_map>
#include <string>

bool isIsomorphic(std::string s, std::string t)
{
    if(s.size() != t.size())
        return false;
    std::unordered_map<char, char> m;
    std::unordered_map<char, char> m2;
    for(int i = 0; i < s.size(); i++)
    {
        if(m2.find(t[i]) == m2.end())
            m2[t[i]] = s[i];
        if(m.find(s[i]) == m.end())
            m[s[i]] = t[i];

        if(m[s[i]] != t[i] || m2[t[i]] != s[i])
            return false;
    }
    return true;
}

int main()
{
    
}