#include <iostream>
#include <vector>
#include <map>
using namespace std;

int maxSubArray(vector<int>& nums) {
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