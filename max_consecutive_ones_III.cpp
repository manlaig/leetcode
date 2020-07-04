#include <unordered_map>
#include <vector>
using namespace std;

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

int longestOnes(vector<int>& A, int K)
{
    return helper(A, 0, K);
}

int main()
{

}