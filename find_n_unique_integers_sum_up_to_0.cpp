#include <vector>

std::vector<int> sumZero(int n)
{
    if(n == 1)
        return {0};
    std::vector<int> v;
    for(int i = 1; i <= (n / 2); i++)
    {
        v.push_back(i);
        v.push_back(-i);
    }
    if((n / 2) * 2 < n)
    {
        v[v.size() - 1] = n/2 + 1;
        v.push_back(-n);
    }
    return v;
}

int main()
{

}