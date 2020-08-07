#include <vector>
#include <string>
#include <stack>

std::string minRemoveToMakeValid(std::string s)
{
    int curr = 0;
    std::stack<char> buf;
    
    for(char c : s)
    {
        if(c == ')' && curr - 1 >= 0)
        {
            buf.push(c);
            curr--;
        }
        else if(c != ')')
        {
            if(c == '(')
                curr++;
            buf.push(c);
        }
    }
    
    std::vector<char> temp;
    temp.reserve(buf.size());
    while(buf.size())
    {
        if(buf.top() == '(' && curr > 0)
            curr--;
        else
            temp.push_back(buf.top());
        buf.pop();
    }
    
    std::string out(temp.size(), ' ');
    for(int i = 0; i < temp.size(); i++)
        out[i] = temp[temp.size() - 1 - i];
    
    return out;
}

int main()
{

}