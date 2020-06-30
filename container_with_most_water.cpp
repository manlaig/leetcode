#include <vector>

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