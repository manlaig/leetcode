#include <vector>
#include <string>
using namespace std;

int factorial(int n, int out = 1)
{
    if(n <= 1)
        return out;
    else
        return factorial(n-1, out*n);
}

/*
    This solution takes advantage of the fact that
    (n-1)! permutations exist for every 1st digit from 1 to n
    Knowing how many permutations start with the same digit,
    we can determine the next digit in the permutation
*/

string getPermutation(int n, int k)
{
    // 0-indexed k
    k--;

    vector<int> out(n);
    for(int i = 1; i <= n; i++)
        out[i-1] = i;
    
    string answer = "";
    int size = n-1;
    while(k > 0)
    {
        int fact = factorial(size);
        int index = k / fact;
        
        answer += to_string(out[index]);
        out.erase(out.begin()+index);
        
        k -= fact * index;
        size--;
    }
    for(int i : out)
        answer += to_string(i);
    return answer;
}

int main()
{

}