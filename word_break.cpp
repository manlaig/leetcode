#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

bool helper(const string& s, const unordered_set<string>& dict, int start, int end, vector<int>& dp)
{
    if(start >= end || dict.find(s.substr(start, end-start)) != dict.end())
        return true;
    if(dp[start] != -1)
        return dp[start];

    bool found = false;
    for(int i = start; i < end; i++)
    {
        if(dict.find(s.substr(start, i-start)) != dict.end())
        {
            found = helper(s, dict, i, end, dp);
        }
        if(found)
        {
            break;
        }
    }
    dp[start] = found;
    return found;
}

bool wordBreak(string s, vector<string>& wordDict)
{
    if(!s.size() || !wordDict.size())
        return false;
    unordered_set<string> dict;
    vector<int> dp(s.size(), -1);
    for(string s : wordDict)
        dict.insert(move(s));
    return helper(s, dict, 0, s.size(), dp);
}

int main()
{

}