#include <vector>
#include <list>

int repeatedNTimes(std::vector<int>& A)
{
    std::list<int> l;
    for(int i : A)
    {
        if(l.size() >= 3)
            l.pop_front();
        for(auto it = l.begin(); it != l.end(); it++)
            if(*it == i)
                return i;
        l.push_back(i);
    }
    return A[A.size() - 1];
}

int main()
{
    
}