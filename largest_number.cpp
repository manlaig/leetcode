#include <string>
#include <vector>
using namespace std;

/*
    Will be get a larger number by putting n2 in front of n1?
    Which way of arrangin the two would result in a larger number?
*/
bool comp(int n1, int n2)
{
    string s1 = to_string(n1) + to_string(n2);
    string s2 = to_string(n2) + to_string(n1);
    return s1.compare(s2) > 0;
}

string largestNumber(vector<int>& nums)
{
    sort(nums.begin(), nums.end(), comp);
    string s = "";
    int canAdd=false;
    for(int num : nums)
    {
        if(num)
            canAdd = true;
        if(canAdd)
            s += to_string(num);
    }
    
    if(!s.size() && nums.size())
        return "0";
        
    return s;
}

int main()
{

}