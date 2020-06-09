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
    if(!root)
        return 0;
    return std::max(getHeight(root->left), getHeight(root->right)) + 1;
}

int diameterOfBinaryTree(TreeNode* root)
{
    if(!root)
        return 0;
    int left = getHeight(root->left);
    int right = getHeight(root->right);
    return std::max(left + right, std::max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
}

int main()
{

}