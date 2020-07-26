#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

// accepted, but slow
namespace std {
    template <>
    struct hash<std::vector<int>>
    {
        size_t operator()(const vector<int>& v) const
        {
                std::hash<int> hasher;
            size_t seed = 0;
            for (int i : v)
                seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            return seed;
        }
    };
}

vector<vector<int>> threeSum(vector<int>& nums)
{
    if(nums.size() < 3)
        return {};
    vector<vector<int>> out;
    unordered_set<vector<int>> unique;
    
    sort(nums.begin(), nums.end());
    
    for(int i = 0; i < nums.size()-2; i++)
    {
        int left = i+1;
        int right = nums.size()-1;
        while(left < right)
        {
            if(nums[i] + nums[left] + nums[right] == 0)
                unique.insert({nums[i], nums[left++], nums[right--]});
            else if(nums[i] + nums[left] + nums[right] > 0)
                right--;
            else
                left++;
        }
    }
    out.reserve(unique.size());
    for(auto vec : unique)
        out.emplace_back(move(vec));
    return out;
}

// time limit exceeded
vector<vector<int>> threeSum_slow(const vector<int>& nums)
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