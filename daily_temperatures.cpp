#include <vector>
#include <stack>
using namespace std;

std::vector<int> dailyTemperatures(const std::vector<int>& T)
{
    int n = T.size()-1;
    stack<pair<int, int>> s;
    s.push({n, T[n]});
    
    std::vector<int> out(n+1);
    for(int i = n; i >= 0; i--)
    {
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