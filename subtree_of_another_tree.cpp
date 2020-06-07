struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(0), right(0) {}
    TreeNode(int x) : val(x), left(0), right(0) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool sameTree(TreeNode* s, TreeNode* t)
{
    if(!s && !t)
        return true;
    else if(!s || !t)
        return false;
    
    return s->val == t->val && sameTree(s->left, t->left) && sameTree(s->right, t->right);
}
bool isSubtree(TreeNode* s, TreeNode* t)
{
    if(!s)
        return false;
    if(sameTree(s, t))
        return true;
    return isSubtree(s->left, t) || isSubtree(s->right, t);
}

int main()
{
    
}