#include <unordered_set>
#include <string>

int numJewelsInStones(std::string J, std::string S)
{
    std::unordered_set<char> s;
    for(char c : J)
        s.insert(c);
    
    int jewels = 0;
    for(char c : S)
        if(s.find(c) != s.end())
            jewels++;
    return jewels;
}

int main()
{

}