#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

vector<int> findAnagrams(const string& s, const string& p)
{
    unordered_map<char, int> occur, p_occur;
    vector<int> out;
    out.reserve(50);
    
    int n = p.size();
    for(int i = 0; i < n; i++)
    {
        occur[s[i]] = occur.find(s[i]) == occur.end() ? 1 : occur[s[i]] + 1;
        p_occur[p[i]] = p_occur.find(p[i]) == p_occur.end() ? 1 : p_occur[p[i]] + 1;
    }
    
    bool last = false, found = true;
    int size = s.size();
    for(int i = 0; i + n <= size; i++)
    {
        if(i)
        {
            occur[s[i+n-1]]++;
            occur[s[i-1]]--;
        }
        
        // if we are adding and removing the same character to our window,
        // then we don't need to compute the same answer again
        if(last && s[i+n-1] == s[i-1])
            out.push_back(i);
        else if(last && s[i+n-1] != s[i-1])
            last = false;
        else
        {
            found = true;
            for(pair<char, int> p : occur)
                if(p.second != p_occur[p.first])
                    found = false;
            if(found)
            {
                out.push_back(i);
                last = true;
            }   
        }
    }
    return out;
}

int main()
{
    
}