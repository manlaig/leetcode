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

    // given that p can be an ancestor of q, we need to visit every node
    // think through WHY we need to do that
    TreeNode* t = lowestCommonAncestor(root->left, p, q);
    TreeNode* t2 = lowestCommonAncestor(root->right, p, q);
    
    // is p an ancestor of q?
    if(root == p)
        if(!t && !t2 || t == q || t2 == q)
            return root;
    // is q an ancestor of p?
    else if(root == q)
        if(!t && !t2 || t == p || t2 == p)
            return root;
    // does root have p and q BOTH in it's left and right branches?
    else if(t && t2)
        return root;
    return t ? t : t2;
}

int main()
{
    
}