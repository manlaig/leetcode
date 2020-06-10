#include <iostream>
#include <vector>
#include <string>

void helper(std::vector<std::string>& out, std::string str, int open, int close)
{
    if(open == 0 && close == 0)
        out.push_back(str);
    
    if(open > 0)
        helper(out, str + '(', open-1, close);
    if(open < close)
        helper(out, str + ')', open, close-1);
}

std::vector<std::string> generateParenthesis(int n)
{
    std::vector<std::string> out;
    helper(out, "", n, n);
    return out;
}

int main()
{
    for(std::string s : generateParenthesis(3))
        std::cout << s << std::endl;
}
