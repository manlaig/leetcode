#include <iostream>
#include <vector>
#include <set>

// this algorithm is called the Sieve of Eratosthenes
std::vector<int>* generate_primes(int upto)
{
    std::set<int> s;
    for(int curr = 2; curr * curr <= upto; curr++)
        if(s.find(curr) == s.end())
            for(int i = curr * curr; i <= upto; i += curr)
                s.insert(i);

    std::vector<int>* v = new std::vector<int>();
    for(int i = 2; i <= upto; i++)
        if(s.find(i) == s.end())
            v->push_back(i);
    return v;
}

int main()
{
    auto v = generate_primes(100);
    for(int i : *v)
        std::cout << i << " ";
    std::cout << std::endl;
}