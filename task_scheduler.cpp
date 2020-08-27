#include <unordered_map>
#include <vector>
using namespace std;

// a relatively slow solution
int leastInterval(const vector<char>& tasks, int n)
{
    unordered_map<char, int> occur;
    for(char c : tasks)
        occur[c]++;
    
    vector<char> order(occur.size());
    int index = 0;
    for(const pair<char, int>& p : occur)
        order[index++] = p.first;
            
    unordered_map<char, int> last;
    for(char c : order)
        last[c] = -1;
    
    int count = 0;
    int done = 0;
    while(done < tasks.size())
    {
        char greedy = 0;
        int lastGreedy = 0;
        
        for(char c : order)
        {
            if((last[c] == -1 || count - last[c] > n) && occur[c] > lastGreedy)
            {
                lastGreedy = occur[c];
                greedy = c;
            }
        }
        
        if(lastGreedy != 0)
        {
            done++;
            last[greedy] = count;
            occur[greedy]--;
        }
        
        count++;
    }
    return count;
}

int main()
{

}