class Solution
{
public:
    int reverse(int x)
    {
        long long mult = x < 0 ? -1LL : 1LL;
        x = abs(x);
        long long out = 0;
        while(x > 0)
        {
            out = out * 10 + x % 10;
            x /= 10;
        }
        if(mult * out > 2147483647 || mult * out < -2147483648)
            return 0;
        
        return mult * out;
    }
};