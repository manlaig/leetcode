struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(0), right(0) {}
    TreeNode(int x) : val(x), left(0), right(0) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int rangeSumBST(TreeNode* root, int L, int R) {
    if(!root)
        return 0;
    return rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R) +
            (root->val >= L && root->val <= R ? root->val : 0);
    
}

int main()
{

}