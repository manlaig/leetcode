#include <unordered_map>
#include <vector>
using namespace std;

int findBestValue(vector<int>& arr, int target)
{
    unordered_map<int, int> freq;
    int init = 0;
    for(int num : arr)
    {
        // for negative numbers
        init += min(0, num);
        freq[num]++;
    }
    
    int diff = abs(target - init);
    int out = 0;
    int last = INT_MAX;
    int addBy = arr.size();
    
    int i = 1;
    
    // while the absolute difference is decreasing
    while(abs(target - init) < last)
    {
        last = abs(target - init);
        
        // 4 9 3 -> 10
        // 1 1 1 = 3
        // 2 2 2 = 6
        // 3 3 3 = 9
        // 4 4 3 = 11
        // 4 5 3 = 12
        init += addBy;
        addBy -= freq[i];
        
        if(abs(target - init) < diff)
        {
            diff = abs(target - init);
            out = i;
        }
        i++;
    }
    return out;
}

int main()
{

}