#include <algorithm>
#include <vector>
using namespace std;

/*
    An important observation to make here is that the shortest person's spot is already given.
    Because everyone else will be taller than them, people[i][1] is the spot for the shortest person at i
    The next taller person skips enough taller people (elements initialized to INT_MAX) and pick the next available spot
*/

vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
{
    // start with the shortest person
    sort(people.begin(), people.end());
    
    // to avoid overriding
    vector<bool> filled(people.size());
    vector<vector<int>> out(people.size(), {INT_MAX, INT_MAX});
    for(int i = 0; i < people.size(); i++)
    {
        // counting how many taller people encountered so far
        int count = 0;
        int spot = 0;
        for(; spot < out.size(); spot++)
        {
            // if we skipped enough taller people and the spot is empty
            if(count >= people[i][1] && !filled[spot])
                break;

            // need to skip exactly people[i][1] taller people
            if(people[i][0] <= out[spot][0])
                count++;
        }
        out[spot] = people[i];
        filled[spot] = true;
    }
    return out;
}

int main()
{

}