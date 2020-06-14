#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(0), right(0) {}
    TreeNode(int x) : val(x), left(0), right(0) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int getHeight(TreeNode* root)
{
    return !root ? 0 : std::max(getHeight(root->left), getHeight(root->right)) + 1;
}

int helper(TreeNode* root, int depth, int curr = 1)
{
    if(!root)
        return 0;
    if(curr == depth)
        return root->val;
    return helper(root->left, depth, curr+1) + helper(root->right, depth, curr+1);
}

int deepestLeavesSum(TreeNode* root)
{
    return helper(root, getHeight(root));
}

int main()
{

}