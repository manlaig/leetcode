#include <map>
using namespace std;

// Adding: O(logN)
// Lookup: O(N/2)
class MedianFinder_slow
{
    map<int, int> s;
    int size;
public:
    
    MedianFinder_slow() : size(0) {}
    
    void addNum(int num)
    {
        s[num]++;
        size++;
    }
    
    double findMedian()
    {
        int count = 0;
        if(size % 2)
        {
            // 1 2 3 4 5
            for(const pair<int, int>& p : s)
            {
                int remaining = size-count-1-p.second;
                
                if(count+p.second-1 >= remaining)
                    return p.first;
                else
                    count += p.second;
            }
        }
        else
        {
            // 1 2 3 4 5 6
            // 1 2 2 2 2 3
            double first = 0;
            bool init = false;
            
            for(const pair<int, int>& p : s)
            {
                if(init)
                    return (first + p.first) / 2.;
                
                int remaining = size-count-p.second;
                
                if(count+p.second > remaining)
                    return p.first;
                else if(count+p.second == remaining)
                {
                    init = true;
                    first = p.first;
                }
                else
                    count += p.second;
            }
        }
        return 0;
    }
};

int main()
{

}