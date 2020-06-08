int hammingDistance(int x, int y)
{
    int dist = 0;
    while(x || y)
    {
        if(x % 2 != y % 2)
            dist++;
        x /= 2;
        y /= 2;
    }
    return dist;
}

int main()
{
    
}