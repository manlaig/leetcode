#include <string>

std::string longestPalindrome(const std::string& s)
{
    if(s.size() < 2)
        return s;
    
    int odd_most = 1;
    std::string odd_palin = " ";
    odd_palin[0] = s[0];
    for(int i = 1; i < s.size()-1; i++)
    {
        int odd = 1;
        int left = i-1;
        int right = i+1;
        while(left >= 0 && right < s.size() && s[left] == s[right])
        {
            odd += 2;
            left--;
            right++;
        }
        if(odd > odd_most)
        {
            odd_most = odd;
            odd_palin = s.substr(i-odd/2, odd);
        }
    }
    
    int even_most = 0;
    std::string even_palin = "";
    for(int i = 1; i < s.size(); i++)
    {
        int even = 0;
        int left = i-1;
        int right = i;
        while(left >= 0 && right < s.size() && s[left] == s[right])
        {
            even += 2;
            left--;
            right++;
        }
        if(even > even_most)
        {
            even_most = even;
            even_palin = s.substr(i-even/2, even);
        }
    }
    return odd_most > even_most ? odd_palin : even_palin;
}

int main()
{

}