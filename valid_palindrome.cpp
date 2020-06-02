#include <iostream>
#include <string>

bool isPalindrome(std::string s)
{
    std::string new_s = "";
    for(int i = 0; i < s.size(); i++)
        if(!std::ispunct(s[i]) && s[i] != ' ')
            new_s += std::tolower(s[i]);
    int n = new_s.size();
    int mid = n % 2 ? n / 2 + 1 : n / 2;
    
    for(int i = mid; i < n; i++)
        if(new_s[n - 1 - i] != new_s[i])
            return false;
    return true;
}

int main()
{
    std::cout << isPalindrome("abba") << std::endl;
    std::cout << isPalindrome("ababa") << std::endl;
}