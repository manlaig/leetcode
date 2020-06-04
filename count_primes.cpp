#include <vector>

void generate(std::vector<int>& out, int upto)
{
    if(upto <= 1)
        return;
    bool arr[upto+1];
    for(int i = 0; i < upto; i++)
        arr[i] = false;
    for(int i = 2; i * i <= upto; i++)
    {
        if(!arr[i])
            for(int j = i * i; j <= upto; j += i)
                arr[j] = true;
    }
    
    for(int i = 2; i < upto; i++)
        if(!arr[i])
            out.push_back(i);
}

int countPrimes(int n)
{
    std::vector<int> out;
    out.reserve(100);
    generate(out, n);
    return out.size();
}

int main()
{
    
}