#include <iostream>

/*
    IMPORTANT: when doing arithmetic, always handle integer bounds
    LeetCode can test the case where n = -2147483648, since we're doing n-1,
    this case would cause a runtime error in our code, I was careless for not handling it at first
*/

bool isPowerOfTwo(int n)
{
    if(!n || n == -2147483648)
        return false;
    return !(n & (n - 1));
}

int main()
{
    std::cout << isPowerOfTwo(15) << std::endl;
    std::cout << isPowerOfTwo(16) << std::endl;
}