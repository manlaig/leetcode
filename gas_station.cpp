#include <vector>
#include <queue>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
    int left = 0;
    int start = 0;
    int window = 0;
    for(int i = 0; i < gas.size(); i++)
    {
        window += gas[i] - cost[i];
        // the current 'start' doesn't work
        if(window < 0)
        {
            // amount that's left to cover
            left += window;
            // can skip the start to all the way to i + 1
            // because the window [start+1, i) has less extra gas than window [start, i)
            // because gas[start] - cost[start] > 0
            start = i + 1;
            window = 0;
        }
    }
    // starting at 'start' need to cover all the gas that's missing
    return window >= -left ? start : -1;
}

///////////////// SLOWER SOLUTION ///////////////

struct Entry
{
    int index;
    int diff;
};

class Compare
{
public:
    bool operator() (Entry a, Entry b)
    {
        return a.diff > b.diff;
    }
};

int canCompleteCircuit(const vector<int>& gas, const vector<int>& cost)
{
    if(!gas.size() || gas.size() != cost.size())
        return 0;
    
    priority_queue<Entry, vector<Entry>, Compare> q;
    
    int n = gas.size();
    for(int i = 0; i < n; i++)
    {
        q.push({i, gas[i] - cost[i]});
    }
    
    while(q.size())
    {
        Entry e = q.top();
        q.pop();
        int sum = e.diff;

        for(int i = e.index+1; i < n; i++)
        {
            if(sum < 0)
                break;
            sum += gas[i] - cost[i];
        }
        for(int i = 0; i < e.index; i++)
        {
            if(sum < 0)
                break;
            sum += gas[i] - cost[i];
        }
        if(sum >= 0)
            return e.index;
    }
    
    return -1;
}

int main()
{

}