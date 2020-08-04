#include <vector>

/*
    This is kind of similar to how the TwoSum problem is solved.
    We start with 2 bounds, compute a potential answer in each iteration
    and choose the side that can lead to a larger output.
    So, it's a greedy algorithm in that way
*/

int maxArea(std::vector<int>& arr)
{
    int out = 0;
    int left = 0;
    int right = arr.size()-1;
    while(left < right)
    {
        out = std::max(out, (right - left) * std::min(arr[left], arr[right]));
        if(arr[left] > arr[right])
            right--;
        else
            left++;
    }
    return out;
}

int main()
{

}