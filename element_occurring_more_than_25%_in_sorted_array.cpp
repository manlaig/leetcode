#include <vector>

int findSpecialInteger(const vector<int>& arr)
{
    int count = arr.size() / 4;
    for(int i = 0; i + count < arr.size(); i++)
        if(arr[i] == arr[i+count])
            return arr[i];
    return -1;
}

int main()
{

}