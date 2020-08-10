#include <vector>
#include <stack>
using namespace std;

// There's similarity between this solution and the Longest Valid Parantheses solution
std::vector<int> dailyTemperatures(const std::vector<int>& T)
{
    int n = T.size()-1;
    stack<pair<int, int>> s;
    s.push({n, T[n]});
    
    std::vector<int> out(n+1);

    // We start looping from the right because at index i
    // we'll have already visited indices larger than i (can reuse)
    for(int i = n; i >= 0; i--)
    {
        // we don't care about elements smaller than T[i]
        // because we don't need them since indices 0 <= j < i
        // are either smaller than T[i] (in which case out[j] = i-j)
        // or larger than T[i] (in which case T[i] will be popped)
        while(s.size() && s.top().second <= T[i])
            s.pop();
        
        if(!s.empty())
            out[i] = s.top().first - i;
        s.push({i, T[i]});
    }
    return out;
}

int main()
{

}