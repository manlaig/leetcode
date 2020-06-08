#include <vector>
#include <string>

std::vector<std::string> fizzBuzz(int n)
{
    std::vector<std::string> out(n);
    for(int i = 1; i <= n; i++)
    {
        if(i % 5 == 0 && i % 3 == 0)
            out[i-1] = "FizzBuzz";
        else if(i % 3 == 0)
            out[i-1] = "Fizz";
        else if(i % 5 == 0)
            out[i-1] = "Buzz";
        else
            out[i-1] = std::to_string(i);
    }
    return out;
}

int main()
{
    
}