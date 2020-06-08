#include <vector>

int helper(std::vector<int>& arr, int start, int end)
{
    if(start >= end)
        return start;
    int mid = (start + end) / 2;
    if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
        return mid;
    else if(arr[mid] > arr[mid+1])
        return helper(arr, start, mid-1);
    else if(arr[mid] > arr[mid-1])
        return helper(arr, mid+1, end);
    else
    {
        int l = helper(arr, start, mid-1);
        int r = helper(arr, mid+1, end);
        return arr[l] > arr[r] ? l : r;
    }
}

int peakIndexInMountainArray(std::vector<int>& A)
{
    return helper(A, 0, A.size()-1);
}

int main()
{

}