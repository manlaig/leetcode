#include <iostream>
#include <string>
using namespace std;

int nextGreaterElement(int n)
{
    if(n < 0)
        return -1;
    
    string s = to_string(n);
    // 12345 -> 12354
    // 54321 -> -1
    // 645321 -> 651234
    // 645312 -> 645321
    // 666445555333312222
    // 12222333 -> 12223332 -> 12223233
    for(int i = s.size()-2; i >= 0; i--)
    {
        if(s[i] < s[i+1])
        {
            int ref = s.size()-1;
            while(s[ref] <= s[i])
                ref--;
            swap(s[i], s[ref]);
            reverse(s.begin()+i+1, s.end());
            long long out = stoll(s);
            if(out > INT_MAX)
                return -1;
            return out;
        }
    }
    return -1;
}

int main()
{

}