#include <iostream>
#include <set>

void permute_helper(std::set<std::string>* out, std::string str, int start, int end)
{
    if(start >= end)
        return;
    out->insert(str);
    for(int i = start; i < end; i++)
    {
        std::swap(str[start], str[i]);
        permute_helper(out, str, start+1, end);
    }
}

std::set<std::string>* permutations(const std::string& str)
{
    std::set<std::string>* v = new std::set<std::string>();
    permute_helper(v, str, 0, str.size());
    return v;
}

int main()
{
    
}