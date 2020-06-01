#include <iostream>
#include <string>

bool compare(const std::string& src, int start, int end, const std::string& target)
{
    for(int i = start; i < end; i++)
        if(src[i] != target[i-start])
            return false;
    return true;
}

int strStr(std::string haystack, std::string needle) {
    int win_size = needle.size();
    if(!win_size)
        return 0;
    if(haystack.size() < win_size)
        return -1;
    for(int i = 0; i <= haystack.size() - win_size; i++)
    {
        if(compare(haystack, i, i + win_size, needle))
            return i;
    }
    return -1;
}

int main()
{
    std::cout << strStr("helloworld", "world") << std::endl;
}