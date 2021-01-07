#include <map>
#include <vector>
#include <string>
using namespace std;

vector<int> partitionLabels(string S)
{
    map<char, int> last;
    
    for(int i = 0; i < S.size(); i++)
        last[S[i]] = i;
    
    vector<int> out;
    int size = 1;
    for(int i = 0, bound = last[S[0]]; i < S.size(); i++, bound = max(bound, last[S[i]]))
    {
        if(i == bound)
        {
            out.push_back(size);
            size = 0;
        }
        size++;
    }
    if(size > 1)
        out.push_back(size);
    return out;
}

int main()
{

}