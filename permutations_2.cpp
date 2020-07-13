#include <unordered_set>
#include <vector>
using namespace std;

struct VectorHash
{
    size_t operator()(const std::vector<int>& v) const
    {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }
        return seed;
    }
};
void perm(unordered_set<vector<int>, VectorHash>& out, vector<int>& arr, int curr=0)
{
    if(curr == arr.size())
        out.insert(arr);
    
    for(int i = curr; i < arr.size(); i++)
    {
        swap(arr[curr], arr[i]);
        perm(out, arr, curr+1);
        swap(arr[curr], arr[i]);
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums)
{
    unordered_set<vector<int>, VectorHash> unique;
    perm(unique, nums);
    
    vector<vector<int>> out(unique.size());
    int i = 0;
    for(auto& vec : unique)
    {
        out[i++] = move(vec);
    }
    return out;
}

int main()
{

}