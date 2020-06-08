#include <unordered_set>
#include <vector>
#include <stack>
using namespace std;

// unordered_set uses std::hash, so we provide a custom hashing function for our "visited" set
struct pair_hash
{
    inline size_t operator()(const pair<int,int> & v) const
    {
        return v.first*31+v.second;
    }
};

/*
    This is basically DFS, but we still loop through the whole array since the islands are disconnected
*/

int numIslands(const vector<vector<char>>& grid)
{
    int islands = 0;
    stack<pair<int,int>> next;
    unordered_set< pair<int, int>, pair_hash > visited;
    
    for(int row = 0; row < grid.size(); row++)
    {
        for(int col = 0; col < grid[row].size(); col++)
        {
            pair<int, int> temp = make_pair(row, col);
            if(grid[row][col] == '1' && visited.find(temp) == visited.end())
            {
                islands++;
                next.push(temp);
                while(next.size())
                {
                    pair<int, int> p = next.top();
                    next.pop();
                    visited.insert(make_pair(p.first, p.second));
                    
                    p.first -= 1;
                    if(p.first >= 0 && grid[p.first][p.second] == '1'
                        && visited.find(p) == visited.end())
                        next.push(p);
                    
                    p.first += 2;
                    if(p.first < grid.size() && grid[p.first][p.second] == '1'
                        && visited.find(p) == visited.end())
                        next.push(p);
                    
                    p.first -= 1;
                    p.second -= 1;
                    if(p.second >= 0 && grid[p.first][p.second] == '1'
                        && visited.find(p) == visited.end())
                        next.push(p);
                    
                    p.second += 2;
                    if(p.second < grid[row].size() && grid[p.first][p.second] == '1'
                        && visited.find(p) == visited.end())
                        next.push(p);
                }
            }
        }
    }
    return islands;
}

int main()
{

}