#include <vector>

std::vector<bool> kidsWithCandies(std::vector<int>& candies, int extraCandies)
{
    int most = 0;
    for(int i : candies)
        most = std::max(most, i);
    
    std::vector<bool> out(candies.size());
    for(int i = 0; i < candies.size(); i++)
        out[i] = candies[i] + extraCandies >= most ? true : false;
    return out;
}

int main()
{

}