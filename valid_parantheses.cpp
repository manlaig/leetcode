#include <stack>
#include <string>

bool isValid(std::string s)
{
    std::stack<char> p;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '{' || s[i] == '[' || s[i] == '(')
            p.push(s[i]);
        else if(p.empty())
            return false;
        else if(s[i] == '}' && p.top() != '{')
            return false;
        else if(s[i] == ')' && p.top() != '(')
            return false;
        else if(s[i] == ']' && p.top() != '[')
            return false;
        else
            p.pop();
    }
    return p.empty();
}

int main()
{

}