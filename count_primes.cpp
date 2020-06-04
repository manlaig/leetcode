#include <iostream>
#include <vector>

void generate(std::vector<int>& out, int upto)
{
    if(upto <= 1)
        return;
    
    bool non_prime[upto+1];
    // initializing the array, in release mode, it's filled with garbase
    for(int i = 0; i < upto; i++)
        non_prime[i] = false;

    // checking off which numbers are NOT primes
    for(int i = 2; i * i <= upto; i++)
        if(!non_prime[i])
            for(int j = i * i; j <= upto; j += i)
                non_prime[j] = true;
    
    // i is the prime number
    for(int i = 2; i < upto; i++)
        if(!non_prime[i])
            out.push_back(i);
}

int countPrimes(int n)
{
    std::vector<int> out;
    out.reserve(100);       // get avoid resizing often
    generate(out, n);
    return out.size();
}

int main()
{
    std::cout << countPrimes(1000) << std::endl;
    std::cout << countPrimes(10000) << std::endl;
    std::cout << countPrimes(100000) << std::endl;
}