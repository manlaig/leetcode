#include <string>
#include <stack>

/*
There's an edge case to this problem for cases like ()() and (()()
We want to somehow store a buffer for how long the sequence is so far
*/
int longestValidParentheses(std::string s)
{
    std::stack<int> parans;
    parans.push(-1);
    int out = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(')
            parans.push(i);
        else
        {
            parans.pop();
            if(parans.empty())
                parans.push(i);
            else
                out = std::max(out, i - parans.top());
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