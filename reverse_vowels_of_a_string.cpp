#include <iostream>
#include <vector>
#include <string>

bool isVowel(char c)
{
    return (c == 'a') || (c == 'e') || (c == 'u')
        || (c == 'i') || (c == 'o');
}

std::string reverseVowels(std::string s)
{
    std::vector<char*> v;
    for(char& c : s)
        if(isVowel(std::tolower(c)))
            v.push_back(&c);
    for(int i = 0; i < v.size()/2; i++)
        std::swap(*v[i], *v[v.size() - i - 1]);
    
    return s;
}

int main()
{

}