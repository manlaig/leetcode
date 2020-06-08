int subtractProductAndSum(int n)
{
    int orig = n;
    int prod = 1;
    while(n)
    {
        prod *= n % 10;
        n /= 10;
    }
    n = orig;
    int sum = 0;
    while(n)
    {
        sum += n % 10;
        n /= 10;
    }
    return prod - sum;
}

int main()
{

}