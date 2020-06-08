struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(0), right(0) {}
    TreeNode(int x) : val(x), left(0), right(0) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* mergeTrees(TreeNode*& t1, TreeNode*& t2)
{
    if(!t1 && !t2)
        return 0;
    if(!t1 || !t2)
        return t1 ? t1 : t2;
    else
        t1->val += t2->val;
    
    if(!t1->left && t2->left)
        t1->left = t2->left;
    else
        mergeTrees(t1->left, t2->left);

    if(!t1->right && t2->right)
        t1->right = t2->right;
    else
        mergeTrees(t1->right, t2->right);
    return t1;
}

int main()
{

}