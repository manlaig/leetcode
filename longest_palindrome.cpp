#include <unordered_map>
#include <string>

int longestPalindrome(std::string s)
{
    std::unordered_map<char, int> occur;
    for(char c : s)
        occur[c]++;
    
    int out = 0;
    int add = 0;
    for(std::pair<char, int> p : occur)
    {
        if(p.second % 2)
            add = 1;
        out += p.second / 2 * 2;
    }
    return out + add;
}

int main()
{

}