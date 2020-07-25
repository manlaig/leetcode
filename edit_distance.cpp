#include <string>
#include <vector>
using namespace std;

int minDistance(string word1, string word2)
{
    int n1 = word1.size();
    int n2 = word2.size();
    if(!n1 || !n2)
        return max(n1, n2);
    vector<vector<int>> dp(n1, vector<int>(n2));
    
    for(int i = 0; i < n1; i++)
    {
        for(int j = 0; j < n2; j++)
        {
            if(word1[i] == word2[j])
                dp[i][j] = i && j ? dp[i-1][j-1] : max(i, j);
            else
            {
                int insert = j ? dp[i][j-1] : i;
                int del = i ? dp[i-1][j] : j;
                int replace = i && j ? dp[i-1][j-1] : max(i, j);
                dp[i][j] = min({insert, del, replace}) + 1;
            }
        }
    }
    return dp[n1-1][n2-1];
}

int main()
{

}