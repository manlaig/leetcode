struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(0), right(0) {}
    TreeNode(int x) : val(x), left(0), right(0) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// curr starts incrementing when we reach the smallest element
int helper(TreeNode* root, int k, int& curr)
{
    if(!root)
        return 0;
    int l = helper(root->left, k, curr);
    // checking if we have already found the element
    if(curr == k)
        return l;
    // checking if the current element is the kth element
    else if(++curr == k)
        return root->val;
    int r = helper(root->right, k, curr);
    // checking if we have already found the element
    return curr == k ? r : 0;
}

int kthSmallest(TreeNode* root, int k)
{
    int count = 0;
    return helper(root, k, count);
}

int main()
{

}