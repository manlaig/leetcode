#include <vector>
#include <string>
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

void helper(TreeNode* root, vector<string>& out, string curr)
{
    if(!root)
        return;
    if(!root->left && !root->right)
    {
        out.push_back(curr + to_string(root->val));
        return;
    }
    helper(root->left, out, curr + to_string(root->val) + "->");
    helper(root->right, out, curr + to_string(root->val) + "->");
}

vector<string> binaryTreePaths(TreeNode* root)
{
    vector<string> out;
    helper(root, out, "");
    return out;
}

int main()
{
    
}