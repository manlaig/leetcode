#include <iostream>
#include <string>

int palindromeEven(const std::string& s, int start)
{
    int i = start+1;
    int j = start;
    int count = 0;
    while(i < s.size() && j >= 0)
        if(s[i++] != s[j--])
            break;
        else
            count++;
    return count;
}

int palindromeOdd(const std::string& s, int start)
{
    int i = start+1;
    int j = start-1;
    int count = 1;
    while(i < s.size() && j >= 0)
        if(s[i++] != s[j--])
            break;
        else
            count++;
    return count;
}

int countSubstrings(const std::string& s)
{
    int count = 0;
    for(int i = 0; i < s.size(); i++)
    {
        count += palindromeOdd(s, i);
        count += palindromeEven(s, i);
    }
    return count;
}

int main()
{
    std::cout << countSubstrings("aabbcc") << std::endl;
    std::cout << countSubstrings("abcddcba") << std::endl;
    std::cout << countSubstrings("abcabcabc") << std::endl;
}