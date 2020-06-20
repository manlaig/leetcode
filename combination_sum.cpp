#include <vector>
using namespace std;

vector<int> operator+(const vector<int>& a1, int num)
{
    vector<int> out;
    out.reserve(a1.size() + 1);
    
    for(int i : a1)
        out.push_back(i);
    out.push_back(num);
    return out;
}

void helper(vector<vector<int>>& out, const vector<int>& arr, int target, vector<int> so_far, int start)
{
    if(target == 0)
    {
        out.push_back(so_far);
        return;
    }
    if(target < 0)
        return;
    for(int i = start; i < arr.size(); i++)
        helper(out, arr, target - arr[i], so_far + arr[i], i);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    vector<vector<int>> out;
    helper(out, candidates, target, {}, 0);
    return out;
}

int main()
{

}