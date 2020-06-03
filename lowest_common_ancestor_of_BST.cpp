struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if(!root)
        return 0;

    TreeNode* t = lowestCommonAncestor(root->left, p, q);
    TreeNode* t2 = lowestCommonAncestor(root->right, p, q);
    
    if(root == p)
        if(!t && !t2 || t == q || t2 == q)
            return root;
    else if(root == q)
        if(!t && !t2 || t == p || t2 == p)
            return root;
    else
        if(t && t2)
            return root;
    return t ? t : t2;
}