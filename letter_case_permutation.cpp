#include <vector>
#include <string>
using namespace std;

void helper(vector<string>& out, string s, int i=0)
{
    if(i >= s.size())
        out.push_back(s);
    else
    {
        if(isalpha(s[i]))
        {
            s[i] = tolower(s[i]);
            helper(out, s, i+1);
            s[i] = toupper(s[i]);
            helper(out, s, i+1);
        }
        else
            helper(out, s, i+1);
    }
}

vector<string> letterCasePermutation(string S)
{
    vector<string> out;
    helper(out, S);
    return out;
}

int main()
{

}