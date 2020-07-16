#include <vector>
using namespace std;

vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K)
{
    if(!mat.size() || !mat[0].size())
        return {{}};
    
    int m = mat.size();
    int n = mat[0].size();
    
    vector<vector<int>> dp(m, vector<int>(n));
    for(int i = 0; i < mat.size(); i++)
    {
        dp[i][0] = mat[i][0];
        for(int j = 1; j < n; j++)
            dp[i][j] = mat[i][j] + dp[i][j-1];
    }
    
    vector<vector<int>> out(m, vector<int>(n));
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int sum = 0;
            for(int k = 0; k <= K; k++)
            {
                if(i-k >= 0)
                {
                    int t1 = dp[i-k][min(j+K, n-1)];
                    int t2 = j-K-1 >= 0 ? dp[i-k][j-K-1] : 0;
                    sum += t1 - t2;
                }
                if(i+k < m && k != 0)
                {
                    int t1 = dp[i+k][min(j+K, n-1)];
                    int t2 = j-K-1 >= 0 ? dp[i+k][j-K-1] : 0;
                    sum += t1 - t2;
                }
            }
            out[i][j] = sum;
        }
    }
    return out;
}

int main()
{

}