#include <iostream>
#include <vector>

// this solution has good and bad sides
// in the worst case (when all elements are same), it runs SLOWER than the brute force approach
// in most cases, all elements aren't same, so we can say it's runtime is amortized O(NlogN)

int binarySearch(std::vector<int>& arr, int target, int ignore, int start, int end)
{
    if(start > end)
        return -1;
    int mid = (start + end) / 2;
    if(arr[mid] == target && mid > ignore)
        return mid;
    else if(arr[mid] == target && mid == ignore)
    {
        // this is ran only when we have duplicate elements and one of the duplicates
        // has already been selected, so we have to 'ignore' it and pick the other duplicate
        // the other duplicate can be in either left or right side, so we recurse through both
        int t = binarySearch(arr, target, ignore, start, mid-1);
        int t2 = binarySearch(arr, target, ignore, mid+1, end);
        return t != -1 ? t : t2;
    }
    else if(arr[mid] < target)
        return binarySearch(arr, target, ignore,  mid+1, end);
    return binarySearch(arr, target, ignore,  start, mid-1);
}

std::vector<int> twoSum(std::vector<int>& numbers, int target)
{
    for(int i = 0; i < numbers.size(); i++)
    {
        int out = binarySearch(numbers, target - numbers[i], i, 0, numbers.size()-1);
        if(out != -1)
            return {i+1, out+1};
    }
    return std::vector<int>();
}

int main()
{
    
}