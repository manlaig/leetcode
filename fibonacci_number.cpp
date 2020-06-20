#include <iostream>

int fib(int N)
{
    int n1 = 0;
    int n2 = 1;
    for(int i = 2; i <= N; i++)
    {
        int temp = n1 + n2;
        n1 = n2;
        n2 = temp;
    }
    return N == 0 ? 0 : n2;
}

int main()
{
    std::cout << fib(20) << std::endl;
    std::cout << fib(50) << std::endl;
}