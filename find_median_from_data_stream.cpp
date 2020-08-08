#include <vector>
#include <map>
using namespace std;

// Adding: O(N)
// Median: O(1)
class MedianFinder_sort
{
    vector<int> arr;
    
    void insertion_sort()
    {
        if(arr.size() <= 1)
            return;
        int i = arr.size()-1;
        int j = i-1;
        while(j >= 0 && arr[i] < arr[j])
        {
            swap(arr[i], arr[j]);
            i = j--;
        }
    }
    
public:
    /** initialize your data structure here. */
    MedianFinder_sort()
    {
        arr.reserve(100);
    }
    
    void addNum(int num)
    {
        arr.push_back(num);
        insertion_sort();
    }
    
    double findMedian()
    {
        int n = arr.size();
        int mid = n / 2;
        return n % 2 ? arr[mid] : (arr[mid-1] + arr[mid]) / 2.;
    }
};

// Adding: O(logN)
// Median: O(N/2)
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