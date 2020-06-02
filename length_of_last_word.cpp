#include <iostream>
#include <string>

int lengthOfLastWord(std::string s)
{
    if(s.size() == 0)
        return 0;
    int pos = -1;
    int letter_start = -1;
    for(int i = s.size()-1; i >= 0; i--)
    {
        if(s[i] == ' ' && letter_start != -1)
        {
            pos = i;
            break;
        } else if(letter_start == -1 && s[i] != ' ')
            letter_start = i;
    }
    
    return pos == -1 ? letter_start + 1 : letter_start - pos;
}

int main()
{
    std::cout << lengthOfLastWord("hello world") << std::endl;
}