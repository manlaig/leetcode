#include <vector>
using namespace std;

vector<vector<int>> groupThePeople(const vector<int>& arr)
{
    vector<vector<int>> out;
    vector<vector<int>> occur(arr.size()+1, vector<int>());
    
    for(int i = 0; i < arr.size(); i++)
        occur[arr[i]].push_back(i);
    
    // group size
    for(int i = 1; i < occur.size(); i++)
    {
        // # of people in each group
        int s = occur[i].size();
        for(int j = 0; j < s / i; j++)
        {
            vector<int> temp(i);
            for(int k = 0; k < i; k++)
                temp[k] = occur[i][k + i*j];
            out.push_back(temp);
        }
    }
    return out;
}

int main()
{

}