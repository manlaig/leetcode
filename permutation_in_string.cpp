#include <unordered_map>
#include <string>
using namespace std;

bool checkInclusion(const string& s1, const string& s2)
{
    if(s1.size() > s2.size())
        return false;
        
    unordered_map<char,int> m;
    for(int i = 0; i < s1.size(); i++)
    {
        m[s2[i]]++;
        m[s1[i]]--;
    }
    
    // letter occurrences that are missing
    unordered_map<char, int> left;
    for(pair<char, int> p : m)
        if(p.second)
            left[p.first] = p.second;
    
    if(left.empty())
        return true;
    
    for(int i = 1; i + s1.size() <= s2.size(); i++)
    {
        left[s2[i - 1]]--;
        if(left[s2[i - 1]] == 0)
        {
            left.erase(s2[i - 1]);
        }

        left[s2[i + s1.size() - 1]]++;
        if(left[s2[i + s1.size() - 1]] == 0)
        {
            left.erase(s2[i + s1.size() - 1]);
        }
        
        if(left.empty())
            return true;
    }
    return left.empty();
}

///////////////// Time Limit Exceeded /////////////////
bool checkInclusion_slow(const string& s1, const string& s2)
{
    if(s2.size() < s1.size())
        return false;
    
    unordered_map<int, int> m, window;
    for(char c : s1)
        m[c]++;
    
    int size = s1.size();
    for(int i = 0; i + size <= s2.size(); i++)
    {
        if(i == 0)
        {
            for(int j = 0; j < size; j++)
                window[s2[j]]++;
        }
        else
        {
            window[s2[i-1]]--;
            window[s2[i+size-1]]++;
        }
        bool found = true;
        for(pair<int, int> p : m)
            if(p.second != window[p.first])
                found = false;
        if(found)
            return true;
    }
    return false;
}

int main()
{

}