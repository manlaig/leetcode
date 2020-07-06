#include <string>
#include <vector>
using namespace std;

string convert(string s, int numRows)
{
    if(!s.size() || numRows <= 1)
        return s;
    vector<vector<char>> rows(numRows, vector<char>(s.size()));
    
    for(int i = 0; i < s.size(); i++)
    {
        int div = numRows - 1;
        int rem = i % (2 * div);
        if(rem >= div)
            rows[div - rem % div].push_back(s[i]);
        else
            rows[rem % div].push_back(s[i]);
    }
    
    string out;
    for(const auto& vec : rows)
    {
        for(char num : vec)
        {
            if(num)
                out += num;
        }
    }
    return out;
}

int main()
{

}