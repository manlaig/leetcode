#include <iostream>
#include <vector>

/*
    [-2,1,-3,4,-1,2,1,-5,4]
    
    i = 0: [-2]                 = -2
    i = 1: [1]                  = 1
    i = 2: [1, -3]              = -2
    i = 3: [4]                  = 4
    i = 4: [4, -1]              = 3
    i = 5: [4, -1, 2]           = 5
    i = 6: [4, -1, 2, 1]        = 6     this is the answer
    i = 7: [4, -1, 2, 1, -5]    = 1
    i = 9: [4, -1, 2, 1, -5, 4] = 5
*/
int kadanes(std::vector<int> arr)
{
    if(!arr.size())
        return 0;
    int best = arr[0];
    int largest = best;

    for(int i = 1; i < arr.size(); i++)
    {
        best = std::max(best + arr[i], arr[i]);
        largest = std::max(largest, best);
    }
    return largest;
}

int main()
{
    std::cout << kadanes({-1,2,-3,1,-2,3,-1,-2,-3,1,2,3}) << std::endl;
}