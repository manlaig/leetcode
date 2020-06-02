#include <algorithm>
#include <iostream>
#include <vector>

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
{
    // this approach didn't work and I got lazy
    // so I just went with the O(N*logN) approach
    /*int arr[!m ? 1 : m], j = 0;
    int n2 = 0;
    for(int n1 = 0; n2 < n && n1 < m; n1++)
    {
        if(nums1[n1] > nums2[n2])
        {
            arr[j++] = nums1[n1];
            nums1[n1] = nums2[n2++];
        }
    }
    
    int size = nums1.size();
    for(int i = m, t = 0, t2 = n2; i < size; i++)
    {
        if(t < j && t2 < n && arr[t] < nums2[t2])
            nums1[i] = arr[t++];
        else if(t2 < n)
            nums1[i] = nums2[t2++];
        else if(t < j)
            nums1[i] = arr[t++];
    }*/
    for(int i = 0; i < n; i++)
        nums1[i+m] = nums2[i];
    std::sort(nums1.begin(), nums1.end());
}

int main()
{
    
}