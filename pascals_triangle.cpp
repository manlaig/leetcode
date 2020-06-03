#include <vector>

/*
    Compile with -std=c++11 flag
*/

std::vector<std::vector<int>> generate(int numRows)
{
    std::vector<std::vector<int>> out(numRows);
    if(!numRows)
        return out;
    out[0].push_back(1);
    for(int i = 1; i < numRows; i++)
    {
        out[i].reserve(i+1);
        for(int j = 0; j <= i; j++)
        {
            if(j-1 < 0 || j >= i)
                out[i].push_back(1);
            else
                out[i].push_back(out[i-1][j-1] + out[i-1][j]);
        }
    }
    return out;
}

int main()
{

}