#include <vector>
#include <queue>
using namespace std;

struct pair_sort
{
    bool operator()(const vector<int>& a, const vector<int>& b)
    {
        return a[0] + a[1] > b[0] + b[1];
    }
};

vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)
{
    if(!nums1.size() || !nums2.size() || k <= 0)
        return {};
    
    // the contents of the queue is vector<int>,
    // the min heap is stored as a vector<vector<int>>
    // and pair_sort is used to determine the priority
    priority_queue<vector<int>, vector<vector<int>>, pair_sort> q;
    for(int i : nums1)
        for(int j : nums2)
            q.push({i, j});
    
    vector<vector<int>> out;
    out.reserve(k);
    int i = 0;
    while(!q.empty() && i++ < k)
    {
        if(q.top().size())
            out.push_back(q.top());
        q.pop();
    }
    return out;
}

int main()
{
    
}