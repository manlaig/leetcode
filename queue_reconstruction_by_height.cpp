#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
{
    sort(people.begin(), people.end());
    
    vector<bool> filled(people.size());
    vector<vector<int>> out(people.size(), {INT_MAX, INT_MAX});
    for(int i = 0; i < people.size(); i++)
    {
        int count = 0;
        int j = 0;
        for(; j < out.size(); j++)
        {
            if(count >= people[i][1] && !filled[j])
                break;
            if(people[i][0] <= out[j][0])
                count++;
        }
        out[j] = people[i];
        filled[j] = true;
    }
    return out;
}

int main()
{

}