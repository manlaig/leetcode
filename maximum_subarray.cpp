#include <iostream>
#include <vector>
#include <map>
using namespace std;

// O(n) Kadane's algorithm
int maxSubArray(vector<int>& nums)
{
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
    int max = -2147483648;
    int buf = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        buf = nums[i] > nums[i] + buf ? nums[i] : nums[i] + buf;
        if(buf > max)
            max = buf;
    }
    return max;
}

int maxSubArra_DP(vector<int>& nums)
{
    map<pair<int, int>, int> sums;
    
    int largest = -2147483648;
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] > largest)
            largest = nums[i];
        sums[make_pair(i, i)] = nums[i];
    }
    for(int win_size = 1; win_size < nums.size(); win_size++)
    {
        for(int j = 0; j + win_size < nums.size(); j++)
        {
            int sum = sums[make_pair(j, j+win_size-1)] + nums[j+win_size];
            if(sum > largest)
                largest = sum; 
            sums[make_pair(j, j+win_size)] = sum;
        }
    }
    return largest;
}