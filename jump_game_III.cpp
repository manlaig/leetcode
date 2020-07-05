#include <unordered_set>
#include <vector>

bool helper(const std::vector<int>& arr, int start, std::unordered_set<int>& s)
{
    if(start >= arr.size() || s.find(start) != s.end())
        return false;
    if(arr[start] == 0)
        return true;
    s.insert(start);
    return helper(arr, start + arr[start], s) || helper(arr, start - arr[start], s);
}

bool canReach(std::vector<int>& arr, int start)
{
    std::unordered_set<int> s;
    return helper(arr, start, s);
}