#include <vector>
#include <cmath>
using namespace std;

int numSquares(int n)
{
    int k = sqrt(n);
    
    // dp[n][k] = min number of squares up to k that add up to n
    vector<vector<int>> dp(n+1, vector<int>(k+1));
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= k; j++)
        {
            // INT_MAX to force the use of 1 in dp[i][j]
            // when j == 1, the else clause will be run
            int t = j == 1 ? INT_MAX : dp[i][j-1];
            if(i - j*j < 0)
                dp[i][j] = t;
            else
                dp[i][j] = min(dp[i - j*j][j]+1, t);
        }
    
    return dp[n][k];
}

int main()
{

}