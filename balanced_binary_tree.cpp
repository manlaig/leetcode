#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int height(TreeNode* root)
{
    if(!root)
        return 1;
    return std::max(height(root->left), height(root->right)) + 1;
}

bool isBalanced(TreeNode* root)
{
    if(!root)
        return true;
    int diff = std::abs(height(root->left) - height(root->right));
    return isBalanced(root->left) && isBalanced(root->right) && diff <= 1;
}

int main()
{
    
}