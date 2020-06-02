struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool helper(TreeNode* left, TreeNode* right)
{
    if(!left && !right)
        return true;
    else if(!left || !right || left->val != right->val)
        return false;
    return helper(left->left, right->right) && helper(left->right, right->left);
}

bool isSymmetric(TreeNode* root)
{
    return !root ? true : helper(root->left, root->right);
}