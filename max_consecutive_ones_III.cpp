#include <unordered_map>
#include <vector>
using namespace std;

/*
    The idea of this solution is to place the start at the right place
    because we only compute the solution at the end of the function.

    We expand the window as long as we can go and stop expanding once
    we reach k=0, seeing a 0 means we can expand again.

    101011101111110   k = 2
    |     |
     |     |
      |          |
*/

//////////////// faster solution //////////////////
int longestOnes(vector<int>& A, int K)
{
    int start = 0;
    for(int end = 0; end < A.size(); end++)
    {
        if(A[end] == 0)
            K--;
        if(K < 0)
        {
            // allowing to expand again
            if(A[start] == 0)
                K++;
            // keep the window size the same
            start++;
        }
    }
    return A.size() - start;
}

/////////////////// slow solution //////////////////
int helper(const vector<int>& arr, int start, int k, int curr = 0)
{
    if(start >= arr.size())
    {
        return curr;
    }
    if(arr[start] == 1)
    {
        return helper(arr, start+1, k, curr+1);
    }
    if(k > 0)
    {
        return max(helper(arr, start+1, k-1, curr+1), helper(arr, start+1, k));
    }
    return max(curr, helper(arr, start+1, k, 0));
}

int longestOnes_slow(vector<int>& A, int K)
{
    return helper(A, 0, K);
}

int main()
{

}