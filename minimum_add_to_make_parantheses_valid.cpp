#include <string>

int minAddToMakeValid(std::string S)
{
    int out = 0;
    int curr = 0;
    
    for(char c : S)
    {
        if(c == ')')
        {
            if(curr == 0)
                out++;
            else
                curr--;
        }
        else if(c == '(')
            curr++;
    }
    return out + curr;
}

int main()
{

}