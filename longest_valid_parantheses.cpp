#include <string>

int longestValidParentheses(const std::string& s)
{
    if(!s.size())
        return 0;
    
    int out = 0;
    for(int i = 0; i < s.size()-1; i++)
    {
        int curr = 0;
        for(int j = i; j < s.size(); j++)
        {
            if(s[j] == '(')
                curr++;
            else
                curr--;
            
            if(curr < 0)
                break;
            else if(curr == 0)
                out = std::max(out, j - i + 1);
        }
    }
    return out;
}

int main()
{
    
}