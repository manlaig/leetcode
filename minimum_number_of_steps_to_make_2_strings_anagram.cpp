#include <unordered_map>
#include <string>

int minSteps(std::string s, std::string t)
{
    std::unordered_map<int, int> occur;
    for(int i = 0; i < s.size(); i++)
    {
        occur[s[i]]++;
        occur[t[i]]--;
    }
    int total = 0;
    for(auto p : occur)
        if(p.second > 0)
            total += p.second;
    return total;
}

int main()
{

}