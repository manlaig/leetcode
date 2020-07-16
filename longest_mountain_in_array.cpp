#include <vector>

int longestMountain(std::vector<int>& A)
{
    int start = 0;
    int peak = -1;
    int out = 0;
    bool canStart = true;
    for(int i = 1; i < A.size(); i++)
    {
        if(A[i] < A[i-1])
        {
            if(peak == -1 && i-2 >= 0 && A[i-1] > A[i-2])
            {
                peak = i-1;
                canStart = false;
            }
        }
        else if(A[i] > A[i-1])
        {
            if(peak != -1 && !canStart)
            {
                out = std::max(out, i - start);
                peak = -1;
                canStart = true;
            }
            if(canStart)
            {
                start = i-1;
                canStart = false;
            }
        }
        else
        {
            if(peak != -1)
            {
                out = std::max(out, i - start);
                peak = -1;
            }
            canStart = true;
        }
    }
    int n = A.size();
    if(peak != -1)
        out = std::max(out, n - start);
    return out;
}

int main()
{

}