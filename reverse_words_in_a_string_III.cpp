#include <iostream>
#include <string>

void reverse(std::string& str, int from, int to)
{
    for(int i = 0; i < (to-from)/2; i++)
        std::swap(str[i+from], str[to - i - 1]);
}

std::string reverseWords(std::string s)
{
    int from = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == ' ')
        {
            reverse(s, from, i);
            from = i+1;
        }
    }
    reverse(s, from, s.size());
    return s;
}

int main()
{
    std::cout << reverseWords("Hello world") << std::endl;
}