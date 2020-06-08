#include <unordered_map>
#include <string>
using namespace std;

int firstUniqChar(string s)
{
    unordered_map<char, int> occur;
    for(const char& c : s)
        occur[c]++;
    for(int i = 0; i < s.size(); i++)
        if(occur[s[i]] == 1)
            return i;
    return -1;
}

int main()
{

}