#include <unordered_map>
#include <vector>
#include <list>
#include <map>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k)
{
    unordered_map<int, int> occur;  // keeps track of occurrence of each letter
    // a list as a value because different letters can occur in equal amount of times
    map<int, list<int>> flip;       // maintains ordering, we can order by the occurence

    for(int num : nums)
        occur[num]++;
    
    for(pair<int, int> p : occur)
        flip[p.second].push_back(p.first);
    
    int kk = 0;
    vector<int> out;
    // traversing from the end (starting from most occurred letters)
    for(auto it = flip.rbegin(); it != flip.rend(); it++)
    {
        for(auto iter = it->second.begin(); iter != it->second.end() && kk < k; iter++, kk++)
            out.push_back(*iter);
    }
    
    return out;
}

int main()
{

}