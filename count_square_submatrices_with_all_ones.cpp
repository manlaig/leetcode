#include <vector>

/*
    The idea of this solution is to make a matrix to tell the number of different sizes
    of squares that can start at a particular row and column in the input matrix.
*/

int countSquares(std::vector<std::vector<int>>& matrix)
{
    if(!matrix.size())
        return 0;
    
    int m = matrix.size();
    int n = matrix[0].size();
    std::vector<std::vector<int>> dp(m, std::vector<int>(n));
    
    int sum = 0;
    for(int row = 0; row < m; row++)
    for(int col = 0; col < n; col++)
    {
        if(!std::min(row, col))
            dp[row][col] = matrix[row][col];
        else if(matrix[row][col])
            dp[row][col] = std::min({dp[row-1][col], dp[row][col-1], dp[row-1][col-1]}) + 1;
        else
            dp[row][col] = 0;
        sum += dp[row][col];
    }
    return sum;
}

int main()
{

}