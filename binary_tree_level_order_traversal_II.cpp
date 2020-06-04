#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(0), right(0) {}
    TreeNode(int x) : val(x), left(0), right(0) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int getHeight(TreeNode* root, int curr = 0)
{
    if(!root)
        return curr;
    return std::max(getHeight(root->left, curr+1), getHeight(root->right, curr+1));
}

void fill(std::vector<std::vector<int> >& out, TreeNode* root, int depth, int curr = 0)
{
    if(!root)
        return;
    out[depth - curr - 1].push_back(root->val);
    fill(out, root->left, depth, curr+1);
    fill(out, root->right, depth, curr+1);
}

std::vector<std::vector<int>> levelOrderBottom(TreeNode* root)
{
    std::vector<std::vector<int> > out;
    int depth = getHeight(root);
    out.resize(depth);
    fill(out, root, depth);
    return out;
}

int main()
{
    
}