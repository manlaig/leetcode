#include <string>

bool helper(const std::string& s, int left, int right, bool deleted=false)
{
    if(left >= right)
        return true;
    if(s[left] == s[right])
        return helper(s, left+1, right-1, deleted);
    if(deleted)
        return false;
    return helper(s, left+1, right, true) || helper(s, left, right-1, true);
}

bool validPalindrome(std::string s)
{
    if(!s.size())
        return true;
    return helper(s, 0, s.size()-1);
}

int main()
{

}