#include <vector>

std::vector<int> getRow(int rowIndex)
{
    // O(k) extra space
    std::vector<int> out(rowIndex+1);
    out[0] = 1;
    for(int i = 1; i <= rowIndex; i++)
    {
        long long t = (((long long) out[i-1]) * (rowIndex - i + 1));
        out[i] = t / i;
    }
    return out;
}

int main()
{
    
}