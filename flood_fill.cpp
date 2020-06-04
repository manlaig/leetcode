#include <vector>
#include <set>
#include <stack>

std::vector<std::vector<int> > floodFill(std::vector<std::vector<int> >& image, int sr, int sc, int newColor)
{
    if(!image.size())
        return image;
    
    std::stack<std::pair<int, int> > next;
    std::set<std::pair<int, int> > visited; 
    int orig = image[sr][sc];
    int num_rows = image.size();
    int num_cols = image[0].size();
    
    next.push(std::make_pair(sr, sc));
    
    while(!next.empty())
    {
        std::pair<int,int> coord = next.top();
        next.pop();
        
        if(visited.find(coord) != visited.end())
            continue;
        
        image[coord.first][coord.second] = newColor;
        visited.insert(coord);
        
        if(coord.first + 1 < num_rows && image[coord.first + 1][coord.second] == orig)
            next.push(std::make_pair(coord.first + 1, coord.second));
        
        if(coord.first - 1 >= 0 && image[coord.first - 1][coord.second] == orig)
            next.push(std::make_pair(coord.first - 1, coord.second));
        
        if(coord.second + 1 < num_cols && image[coord.first][coord.second + 1] == orig)
            next.push(std::make_pair(coord.first, coord.second + 1));
        
        if(coord.second - 1 >= 0 && image[coord.first][coord.second - 1] == orig)
            next.push(std::make_pair(coord.first, coord.second - 1));
    }
    return image;
}

int main()
{
    
}