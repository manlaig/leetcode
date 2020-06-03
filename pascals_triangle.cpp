#include <vector>

std::vector<std::vector<int> > generate(int numRows)
{
    std::vector<std::vector<int> > out(numRows);
    // we fill the 0th row with 1, so need to make sure numRows > 0
    if(!numRows)
        return out;
    out[0].push_back(1);

    /*
        we add values directly above and one to the left
        imagine having 0s like this
          0 1 0
         0 1 1 0
        0 1 2 1 0
       0 1 3 3 1 0
        1 4 6 4 1
    */
    for(int i = 1; i < numRows; i++)
    {
        out[i].reserve(i+1);
        for(int j = 0; j <= i; j++)
        {
            // j >= i for limiting how many elements in each row
            // j-1 < 0 for making use our array access is in bounds
            // if the below condition is false, then we're at the edge,
            // in that case, we fill it with a 1
            if(j-1 < 0 || j >= i)
                out[i].push_back(1);
            else
                out[i].push_back(out[i-1][j-1] + out[i-1][j]);
        }
    }
    return out;
}

int main()
{

}