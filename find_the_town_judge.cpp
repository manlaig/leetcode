#include <unordered_map>
#include <vector>

// compile with C++11
int findJudge(int N, const std::vector<std::vector<int>>& trust)
{
    if(N == 1)
        return 1;
    std::unordered_map<int, int> out, in;
    
    for(const std::vector<int>& v : trust)
    {
        in[v[1]] = in.find(v[1]) == in.end() ? 1 : in[v[1]] + 1;
        out[v[0]] = out.find(v[0]) == out.end() ? 1 : out[v[0]] + 1;
    }

    for(std::pair<int, int> p : in)
        if(p.second == N-1 && out.find(p.first) == out.end())
            return p.first;
    return -1;
}

int main()
{

}