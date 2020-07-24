#include <vector>
#include <algorithm>
using namespace std;

void dfs(const vector<int>& arr, vector<vector<int>>& out, vector<int> next, int left, int curr)
{
    if(left == 0)
    {
        out.push_back(next);
    }
    
    for(int i = curr+1; i < arr.size(); i++)
    {
        if(left - arr[i] >= 0)
        {
            next.push_back(arr[i]);
            dfs(arr, out, next, left-arr[i], i);
            next.pop_back();
            while(i+1 < arr.size() && arr[i] == arr[i+1])
                i++;
        }
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> out;
    dfs(candidates, out, {}, target, -1);
    return out;
}

int main()
{

}