#include <unordered_map>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums)
{
    if(!nums.size())
        return {};
    unordered_map<int, list<int>> occur;
    for(int i = 0; i < nums.size(); i++)
        occur[nums[i]].push_back(i);
    
    set<vector<int>> unique;
    for(int i = 0; i < nums.size()-1; i++)
    {
        for(int j = i + 1; j < nums.size(); j++)
        {
            int c = -(nums[i]+nums[j]);
            vector<int> v = { nums[i], nums[j], c };
            sort(v.begin(), v.end());
            
            for(auto iter = occur[c].begin(); iter != occur[c].end(); iter++)
                if(*iter > i && *iter > j)
                {
                    unique.insert(v);
                    break;
                }
        }
    }
    vector<vector<int>> out(unique.size(), vector<int>(3, 1));
    int i = 0;
    for(vector<int> s : unique)
        out[i++] = s;
    return out;
}

int main()
{
    
}