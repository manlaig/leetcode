#include <iostream>
#include <string>
#include <vector>
using namespace std;

// NOTE: compile with -std=c++17 flag

struct Type
{
    bool star = false;
    bool dot = false;
    char val = 0;
};

bool check(const string& s, const vector<Type>& p, int i = 0, int p_i = 0)
{
    // both the pattern and the string are empty
    if(i >= s.size() && p_i >= p.size())
        return true;

    // only the pattern has finished, they are remaining chars that're unmatched
    if(p_i >= p.size())
        return false;

    // if the string is empty, then stars can be interpreted as empty chars
    if(i >= s.size())
    {
        while(p_i < p.size())
            if(!p[p_i++].star)
                return false;
        return true;
    }
    
    if(s[i] == p[p_i].val)
    {
        if(p[p_i].star)
            return check(s, p, i, p_i+1) || check(s, p, i+1, p_i);
        else
            return check(s, p, i+1, p_i+1);
    }
    else if(p[p_i].dot && p[p_i].star)
        return check(s, p, i, p_i+1) || check(s, p, i+1, p_i);
    else if(p[p_i].dot)
        return check(s, p, i+1, p_i+1);
    else if(p[p_i].star)
        return check(s, p, i, p_i+1);
    return false;
}

bool isMatch(string s, string p)
{
    if(!s.size() && !p.size())
        return true;
    
    vector<Type> pattern;
    for(int i = 0; i < p.size(); i++)
    {
        if(p[i] == '.')
        {
            if(i+1 < p.size() && p[i+1] == '*')
            {
                pattern.push_back({true, true, 0});
                // skip the * at i+1
                i++;
            }
            else
                pattern.push_back({false, true, 0});
        }
        // * can't be at 
        else
        {
            if(i+1 < p.size() && p[i+1] == '*')
            {
                pattern.push_back({true, false, p[i]});
                i++;
            }
            else
                pattern.push_back({false, false, p[i]});
        }
    }
    
    return check(s, pattern);
}

int main()
{

}