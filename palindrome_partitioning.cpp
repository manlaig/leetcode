#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

void palindrome_odd(unordered_map<int, vector<int>>& dp, string s, int i)
{
    dp[i].push_back(i+1);
    int left = i-1;
    int right = i+1;
    while(left >= 0 && right < s.size() && s[left] == s[right])
    {
        dp[left].push_back(right+1);
        left--;
        right++;
    }
}

void palindrome_even(unordered_map<int, vector<int>>& dp, string s, int i)
{
    int left = i;
    int right = i+1;
    while(left >= 0 && right < s.size() && s[left] == s[right])
    {
        dp[left].push_back(right+1);
        left--;
        right++;
    }
}

void fill(string s, vector<vector<string>>& out, unordered_map<int, vector<int>>& dp, int i, vector<string>& next)
{
    if(i >= s.size())
    {
        out.push_back(next);
        return;
    }
    for(auto end : dp[i])
    {
        next.push_back(s.substr(i, end-i));
        fill(s, out, dp, end, next);
        next.pop_back();
    }
}

vector<vector<string>> partition(string s)
{
    // dp[i] = all the indices where the palindrome at i ends
    unordered_map<int, vector<int>> dp;
    for(int i = 0; i < s.size(); i++)
    {
        palindrome_odd(dp, s, i);
        palindrome_even(dp, s, i);
    }
    vector<vector<string>> out;
    vector<string> tmp;
    fill(s, out, dp, 0, tmp);
    return out;
}

int main()
{

}