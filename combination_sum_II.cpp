#include <vector>
#include <algorithm>
using namespace std;

void dfs(const vector<int>& arr, vector<vector<int>>& out, vector<int>& next, int left, int curr)
{
    if(left == 0)
    {
        out.push_back(next);
    }
    
    // +1 to avoid using the same element more than once
    for(int i = curr+1; i < arr.size(); i++)
    {
        if(left - arr[i] >= 0)
        {
            next.push_back(arr[i]);
            dfs(arr, out, next, left-arr[i], i);
            next.pop_back();
            
            // the duplicate elements are already used by
            // recursive calls, so skip them here
            while(i+1 < arr.size() && arr[i] == arr[i+1])
                i++;
        }
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> out;
    vector<int> tmp;
    dfs(candidates, out, tmp, target, -1);
    return out;
}

int main()
{

}