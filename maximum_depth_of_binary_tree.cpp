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

/*
    This is a slow solution, I might update my solution later.
    I'm thinking of making of iterative
*/

int maxDepth(TreeNode* root, int depth = 0)
{
    if(!root)
        return depth;
    return std::max(maxDepth(root->left, depth + 1), maxDepth(root->right, depth + 1));
}

int main()
{
    
}