#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(0), right(0) {}
    TreeNode(int x) : val(x), left(0), right(0) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inorder(TreeNode* root, std::vector<int>& out)
{
    if(!root)
        return;
    inorder(root->left, out);
    out.push_back(root->val);
    inorder(root->right, out);
}

TreeNode* increasingBST(TreeNode* root)
{
    std::vector<int> out;
    inorder(root, out);
    
    TreeNode* root2 = 0, *curr = 0;
    for(int num : out)
    {
        if(!curr)
        {
            root2 = new TreeNode(num);
            curr = root2;
        }
        else
        {
            curr->right = new TreeNode(num);
            curr = curr->right;
        }
    }
    return root2;
}

int main()
{

}