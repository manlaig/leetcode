#include <string>

int longestValidParentheses(const std::string& s)
{
    int curr = 0;
    int start = 0;
    int out = 0;
    int peak = 0;
    
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(')
        {
            curr++;
            peak++;
        }
        else
        {
            curr--;
            if(curr > 0)
                out = std::max(out, (peak - curr)*2);
            peak--;
        }
        
        if(curr < 0)
        {
            start = i+1;
            peak = 0;
            curr = 0;
        }
        else if(curr == 0)
        {
            out = std::max(out, i - start + 1);
            peak = 0;
        }
    }
    return out;
}

// time limit exceeded
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