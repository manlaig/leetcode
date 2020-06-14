#include <vector>

/*
    This solution uses DP. The approach is as follows:
    At i,j calculate the minimum path to reach it. That is arr[i][j] plus the minimum of reaching i-1,j or i,j-1
*/

int minPathSum(const std::vector<std::vector<int>>& grid)
{
    if(grid.size() == 0)
        return 0;

    int m = grid.size();
    int n = grid[0].size();
    std::vector<std::vector<int>> dp(m, std::vector<int>(n,1));
    
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
        {
            dp[i][j] = grid[i][j];
            // if i = 0 and j = 0, then we'll add INT_MAX to dp[i][j] and we don't want that
            if(i || j)
                dp[i][j] += std::min(i-1 >= 0 ? dp[i-1][j] : INT_MAX, j-1 >= 0 ? dp[i][j-1] : INT_MAX);
        }
    return dp[m-1][n-1];
}

int main()
{

}