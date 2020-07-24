#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

void dfs(const vector<int>& arr, vector<int>& out, int curr, int mult, vector<int>& best, unordered_map<int, int>& dp)
{
    if(out.size() > best.size())
        best = out;
    if(out.size() <= dp[curr] && dp[curr])
        return;
    for(int i = curr+1; i < arr.size(); i++)
    {
        if((mult && arr[i] % mult == 0) || mult % arr[i] == 0)
        {
            out.push_back(arr[i]);
            dfs(arr, out, i, max(mult, arr[i]), best, dp);
            out.pop_back();
        }
    }
    dp[curr] = out.size();
}

vector<int> largestDivisibleSubset(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    vector<int> out, best;
    out.reserve(50);
    best.reserve(50);
    unordered_map<int, int> dp;
    
    dfs(nums, out, -1, 1, best, dp);
    return best;
}

int main()
{

}