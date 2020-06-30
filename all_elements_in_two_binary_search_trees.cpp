#include <algorithm>
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

void inorder(TreeNode* root, vector<int>& arr)
{
    if(!root)
        return;
    inorder(root->left, arr);
    arr.push_back(root->val);
    inorder(root->right, arr);
}

std::vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
{
    std::vector<int> arr;
    arr.reserve(25);
    
    inorder(root1, arr);
    inorder(root2, arr);
    
    std::sort(arr.begin(), arr.end());
    return arr;
}

int main()
{

}