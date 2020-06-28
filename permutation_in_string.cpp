#include <unordered_map>
#include <string>
using namespace std;

bool checkInclusion(const string& s1, const string& s2)
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