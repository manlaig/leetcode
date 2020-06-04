#include <algorithm>
#include <vector>

// compile with -std=c++11
int twoCitySchedCost(std::vector<std::vector<int>>& costs)
{
    std::sort(costs.begin(), costs.end(), [](std::vector<int>& a, std::vector<int>& b) { return a[1] - a[0] < b[1] - b[0]; });
    
    int total = 0;
    for(int i = 0; i < costs.size(); i++)
        total += i < costs.size() / 2 ? costs[i][1] : costs[i][0];
    return total;
}

int main()
{

}