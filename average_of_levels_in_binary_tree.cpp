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
 
void helper(TreeNode* root, int depth, unordered_map<int, vector<int>>& vals)
{
    if(!root)
        return;
    vals[depth].push_back(root->val);
    helper(root->left, depth+1, vals);
    helper(root->right, depth+1, vals);
}

vector<double> averageOfLevels(TreeNode* root)
{
    unordered_map<int, vector<int>> vals;
    helper(root, 0, vals);
    
    vector<double> out(vals.size());
    for(const auto& p : vals)
    {
        double sum = 0;
        for(int num : p.second)
            sum += num;
        out[p.first] = sum / p.second.size();
    }
    return out;
}

int main()
{
    
}