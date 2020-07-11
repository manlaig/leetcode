#include <vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix)
{
    for(int i = 0; i < matrix.size(); i++)
        for(int j = 0; j < matrix[i].size(); j++)
        {
            if(matrix[i][j] == 0)
            {
                matrix[i][j] = 19981025;
                for(int row = 0; row < matrix.size(); row++)
                    if(matrix[row][j] != 0)
                        matrix[row][j] = 19981025;
                for(int col = 0; col < matrix[i].size(); col++)
                    if(matrix[i][col] != 0)
                        matrix[i][col] = 19981025;
            }
        }
    
    for(int i = 0; i < matrix.size(); i++)
        for(int j = 0; j < matrix[i].size(); j++)
            if(matrix[i][j] == 19981025)
                matrix[i][j] = 0;
}

int main()
{

}