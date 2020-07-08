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

bool check(const string& s, const vector<Type>& p, int i, int p_i)
{
    if(i >= s.size() && p_i >= p.size())
        return true;
    if(p_i >= p.size())
        return false;
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
                i++;
            }
            else
                pattern.push_back({false, true, 0});
        }
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
    
    return check(s, pattern, 0, 0);
}

int main()
{

}