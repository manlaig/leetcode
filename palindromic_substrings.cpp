#include <iostream>
#include <string>

/*
    This solution is called "Expand around center", it is efficient than generating all substrings
    The below 2 helper functions count how many odd and even palindromes exists that start at start

    The fastest algorithm for this problem is called the Manacher's algorithm
*/

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