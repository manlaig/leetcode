struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(0), right(0) {}
    TreeNode(int x) : val(x), left(0), right(0) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int startPath(TreeNode* root, int sum)
{
    if(!root)
        return 0;
    
    int total = sum == 0 ? 1 : 0;
    total += startPath(root->left, sum - root->left->val);
    total += startPath(root->right, sum - root->right->val);
    
    return total;
}

int pathSum(TreeNode* root, int sum)
{
    if(!root)
        return 0;
    return startPath(root, sum-root->val) + pathSum(root->left, sum) + pathSum(root->right, sum);
}

int main()
{

}