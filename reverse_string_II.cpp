#include <string>

void reverse(std::string& s, int from, int to)
{
    for(int i = 0; i < (to - from) / 2; i++)
        std::swap(s[i + from], s[to - i - 1]);
}

std::string reverseStr(std::string s, int k) {
    int i = 0;
    int n = s.size();
    for(; i + 2 * k < n; i += 2 * k)
        reverse(s, i, i + k);
    
    if(i + 2 * k >= n && i + k <= n)
        reverse(s, i, i + k);
    else if(i + k > n)
        reverse(s, i, s.size());
    return s;
}

int main()
{
    
}