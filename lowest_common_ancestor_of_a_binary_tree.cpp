struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};

/*
    This problem is different from "Lowest common ancestor of a binary search tree"
    But, the solution is the same
*/

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if(!root)
        return 0;
    TreeNode* l = lowestCommonAncestor(root->left, p, q);
    TreeNode* r = lowestCommonAncestor(root->right, p, q);
    
    if(l && r)
        return root;
    if((l || r) && (root->val == p->val || root->val == q->val))
        return root;
    if(l || r)
        return l ? l : r;
    if(root->val == p->val || root->val == q->val)
        return root;
    return 0;
}

int main()
{
    
}