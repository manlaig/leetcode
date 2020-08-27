#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*
    This solution can be solved using a greedy approach
    Then, the question is "what" should be pick greedily?
    Few options are:
        1. Earliest/Latest executed tasks
        2. A task that has the most tasks remaining to execute
    
    Option 1 leads to some tasks finish execute earlier and leaves with unnecesssary idles
    Option 2 asks what is the task that can be executed at this point that has the most tasks remaining

    Option 2 avoids finishing some tasks earlier than expected, thus saving idle time for the CPU
*/

// a relatively slow solution
int leastInterval(const vector<char>& tasks, int n)
{
    unordered_map<char, int> occur;
    // last[c]  = time when task 'c' was last executed
    unordered_map<char, int> last;
    unordered_set<char> unique;
    for(char c : tasks)
    {
        occur[c]++;
        last[c] = -1;
        unique.insert(c);
    }
    
    int count = 0;
    int done = 0;
    while(done < tasks.size())
    {
        char greedy = 0;
        int lastGreedy = 0;
        
        for(char c : unique)
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