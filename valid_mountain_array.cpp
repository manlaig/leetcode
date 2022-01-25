#include <vector>
using namespace std;

bool validMountainArray(const vector<int>& arr)
{
    if(arr.size() < 3)
        return false;
    
    bool peak = 0, end = 0;
    
    for(int i = 1; i < arr.size(); i++)
    {
        if(arr[i] > arr[i-1])
        {
            if(end)
                return false;
            peak = 1;
        }
        else if(arr[i] == arr[i-1])
            return false;
        else
            end = 1;
    }
    return peak && end;
}

int main()
{

}