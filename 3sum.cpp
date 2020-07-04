#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

// time limit exceeded
vector<vector<int>> threeSum(const vector<int>& nums)
{
    map<int, int> s;
    for(int num : nums)
        s[num]++;
    
    vector<vector<int>> out;
    for(auto it = s.begin(); it != s.end(); it++)
    {
        if(it->second > 2 && 3 * it->first == 0)
            out.push_back({it->first, it->first, it->first});
        auto t1 = it;
        advance(t1, 1);
        for(; t1 != s.end(); t1++)
        {
            if(it->second > 1 && t1->first + 2 * it->first == 0)
            {
                out.push_back({it->first, it->first, t1->first});
            }
            if(t1->second > 1 && it->first + 2 * t1->first == 0)
            {
                out.push_back({it->first, t1->first, t1->first});
            }
            auto t2 = t1;
            advance(t2, 1);
            for(; t2 != s.end(); t2++)
            {
                if(it->first + t1->first + t2->first == 0)
                    out.push_back({it->first, t1->first, t2->first});
            }
        }
    }
    return out;
}

int main()
{
    
}