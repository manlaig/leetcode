#include <unordered_map>
#include <string>

int lengthOfLongestSubstring(const std::string& s)
{
    std::unordered_map<char, int> occur;
    int best = 0;
    int start = 0;
    int i = 0;
    for(; i < s.size(); i++)
    {
        if(occur.find(s[i]) != occur.cend())
        {
            best = std::max(best, i - start);
            for(int j = start; j < occur[s[i]]; j++)
                occur.erase(s[j]);
            start = occur[s[i]]+1;
        }
        occur[s[i]] = i;
    }
    return std::max(best, i - start);
}

int main()
{

}