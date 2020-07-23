#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(0), right(0) {}
    TreeNode(int x) : val(x), left(0), right(0) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
using LL = long long;

void helper(TreeNode* root, int depth, unordered_map<int, pair<LL,int>>& vals)
{
    if(!root)
        return;
    pair<LL,int> temp = vals[depth];
    vals[depth] = make_pair(temp.first + root->val, temp.second + 1);
    helper(root->left, depth+1, vals);
    helper(root->right, depth+1, vals);
}

vector<double> averageOfLevels(TreeNode* root)
{
    unordered_map<int, pair<LL, int>> vals;
    helper(root, 0, vals);
    
    vector<double> out(vals.size());
    for(const auto& p : vals)
    {
        out[p.first] = p.second.first / (double) p.second.second;
    }
    return out;
}

int main()
{

}