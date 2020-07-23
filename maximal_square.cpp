#include <vector>

int maximalSquare(std::vector<std::vector<char>>& mat)
{
    if(!mat.size() || !mat[0].size())
        return 0;
    std::vector<std::vector<int>> sqr(mat.size(), std::vector<int>(mat[0].size()));
    
    int dim = 0;
    for(int i = 0; i < mat.size(); i++)
    {
        for(int j = 0; j < mat[i].size(); j++)
        {
            if(mat[i][j] == '1')
            {
                if(i > 0 && j > 0)
                    sqr[i][j] = std::min({sqr[i-1][j-1], sqr[i-1][j], sqr[i][j-1]})+1;
                else
                    sqr[i][j] = 1;
                dim = std::max(dim, sqr[i][j]);
            }
        }
    }
    return dim*dim;
}

int main()
{

}