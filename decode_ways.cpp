#include <unordered_map>
#include <iostream>
#include <string>

/*
    This solution uses tree recursion along with dynamic programming
    You can say the solution is O(N) time and O(N) space

    In fact, this solution beat 100% of C++ submissions, in terms of speed.
*/

int helper(const std::string& s, int start, std::unordered_map<int, int>& m)
{
    if(start > s.size())
        return 0;
    else if(m.find(start) != m.end())
        return m[start];
    // we can remove these nested parantheses, but C++ gives warnings then
    else if(start == s.size() || (start == s.size() - 1 && s[start] > '0'))
        return 1;
    else if(s[start] <= '0')
        return 0;
    
    int total = helper(s, start+1, m);
    // we can remove these nested parantheses, but C++ gives warnings then
    if((s[start] == '2' && s[start+1] <= '6') || (s[start] == '1' && s[start+1] <= '9'))
        total += helper(s, start+2, m);
    m[start] = total;
    return total;
}

int numDecodings(std::string s)
{
    std::unordered_map<int,int> m;
    return helper(s, 0, m);
}

int main()
{
    std::cout << numDecodings("12345678910") << std::endl;
    std::cout << numDecodings("10203040") << std::endl;
}