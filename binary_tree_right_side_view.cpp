struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(0), right(0) {}
    TreeNode(int x) : val(x), left(0), right(0) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
    You can also you DFS for this problem
*/

void helper(TreeNode* root, vector<int>& out, int curr, int& most)
{
    if(!root)
        return;
    
    if(curr > most)
    {
        most = curr;
        out.push_back(root->val);
    }
        
    helper(root->right, out, curr+1, most);
    helper(root->left, out, curr+1, most);
}

vector<int> rightSideView(TreeNode* root)
{
    vector<int> out;
    int most = -1;
    helper(root, out, 0, most);
    return out;
}

int main()
{

}