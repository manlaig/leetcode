#include <vector>
#include <queue>

int kthSmallest(std::vector<std::vector<int>>& matrix, int k)
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    int n = matrix.size();
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            q.push(matrix[i][j]);
    
    for(int i = 0; i < k-1; i++)
        q.pop();
    return q.top();
}

int main()
{

}