#include <vector>

int uniquePathsWithObstacles(const std::vector<std::vector<int>>& grid)
{
    if(!grid.size())
        return 0;
    if(grid[0][0])
        return 0;
    int n = grid.size();
    int m = grid[0].size();
    int dp[n][m];
    dp[0][0] = 1;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!i && !j)
                continue;
            if(grid[i][j] != 1)
            {
                int left = j-1 >= 0 ? dp[i][j-1] : 0;
                int top = i-1 >= 0 ? dp[i-1][j] : 0;
                dp[i][j] = left + top;
            }
            else
                dp[i][j] = 0;
        }
    }
    return dp[n-1][m-1];
}

int main()
{

}