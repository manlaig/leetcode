#include <unordered_set>
#include <vector>
#include <stack>

bool helper(const std::vector<int>& arr, int start, std::unordered_set<int>& s)
{
    if(start >= arr.size() || s.find(start) != s.end())
        return false;
    if(arr[start] == 0)
        return true;
    s.insert(start);
    return helper(arr, start + arr[start], s) || helper(arr, start - arr[start], s);
}

bool canReach(const std::vector<int>& arr, int start)
{
    std::unordered_set<int> s;
    return helper(arr, start, s);
}

bool canReach_DFS(const std::vector<int>& arr, int start)
{
    std::stack<int> s;
    std::unordered_set<int> visited;
    s.push(start);
    
    while(!s.empty())
    {
        int top = s.top();
        s.pop();
        visited.insert(top);
        
        if(arr[top] == 0)
            return true;
        
        if(visited.find(arr[top] + top) == visited.end() && arr[top] + top < arr.size())
            s.push(arr[top] + top);
        if(visited.find(top - arr[top]) == visited.end() && top - arr[top] >= 0)
            s.push(top - arr[top]);
    }
    return false;
}

int main()
{
    
}