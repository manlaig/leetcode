#include <unordered_map>
#include <vector>
using namespace std;

int minFallingPathSum(vector<vector<int>>& A)
{
    if(!A.size())
        return 0;

    //dp[i][j] = minimum path to get to ith row and jth col
    unordered_map<int,int> dp[A.size()];

    int out = INT_MAX;
    for(int i = 0; i < A[0].size(); i++)
    {
        dp[0][i] = A[0][i];
        out = min(out, dp[0][i]);
    }
    if(A.size() == 1)
        return out;

    out = INT_MAX;
    for(int row = 1; row < A.size(); row++)
    {
        for(int col = 0; col < A[row].size(); col++)
        {
            int top = dp[row-1][col];
            int left = col-1 >= 0 ? dp[row-1][col-1] : top;
            int right = col+1 < A.size() ? dp[row-1][col+1] : top;
            dp[row][col] = min({dp[row-1][col], left, right}) + A[row][col];
            if(row == A.size()-1)
                out = min(out, dp[row][col]);
        }
    }
    return out;
}