#include <vector>
#include <string>

std::vector<std::vector<int>> largeGroupPositions(std::string S)
{
    std::vector<std::vector<int>> out;
    int start = 0;
    int end = start + 2;
    
    while(end < S.size())
    {
        if(S[start] == S[end] && S[start+1] == S[end])
        {
            while(S[start] == S[end])
                end++;
            out.push_back({start, end-1});
            start = end;
            end = start + 2;
        }
        else
        {
            start++;
            end++;
        }
    }
    return out;
}

int main()
{

}