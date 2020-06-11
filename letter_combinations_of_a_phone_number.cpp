#include <string>
#include <vector>
using namespace std;

vector<string> letterCombinations(string digits)
{
    if(!digits.size())
        return {};
    vector<vector<char>> map = {{'a','b','c'}, {'d','e','f'}, {'g','h','i'}, {'j','k','l'},
                                {'m','n','o'}, {'p','q','r', 's'}, {'t','u','v'}, {'w','x','y','z'}};
    
    int size = 1;
    for(char c : digits)
        if(c - '2' < 0)
            return {};
        else
            size *= map[c - '2'].size();
    
    vector<string> out;
    for(int i = 0; i < size; i++)
    {
        string s;
        s.reserve(digits.size());
        int tmp = size;
        for(char c : digits)
        {
            int n = map[c - '2'].size();
            tmp /= n;
            s.push_back(map[c - '2'][(i / tmp) % n]);
        }
        out.push_back(s);
    }
    
    
    return out;
}

int main()
{
    
}