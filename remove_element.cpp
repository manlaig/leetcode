#include <iostream>
#include <vector>

/*
    This wasnt judged as a fast solution, it's important to note that
    the inner loop runs through whole array 'nums' ONCE in the worst case
    So, the time complexity is NOT O(n^2), but it's O(2N), specifically
*/

int removeElement(std::vector<int>& nums, int val) {
    int last = nums.size() - 1;
    int count = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] == val)
        {
            while(i < last && nums[last] == val)
                last--;
            if(i < last)
                nums[i] = nums[last--];
            count++;
        }
    }
    return nums.size() - count;
}

int main()
{
    std::vector<int> v = {1,2,3,4,4,5,5};
    std::cout << removeElement(v, 4) << std::endl;
    for(int i : v)
        std::cout << i << " ";
    std::cout << std::endl;
}