#include <iostream>
#include <string>

/*
    This kind of technique is called "Two Pointers"
*/

bool isSubsequence(std::string s, std::string t)
{
    int s_i = 0;
    for(int i = 0; i < t.size(); i++)
    {
        if(t[i] == s[s_i])
            if(++s_i == s.size())
                return true;
    }
    return s_i == s.size();
}

int main()
{
    std::cout << isSubsequence("abc", "afwgbflfjec") << std::endl;
}