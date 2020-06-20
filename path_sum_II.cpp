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

void helper(std::vector<std::vector<int>>& paths, TreeNode* root, int sum, std::vector<int> so_far)
{
    if(!root)
        return;
    so_far.push_back(root->val);
    if(sum - root->val == 0 && !root->left && !root->right)
        paths.push_back(so_far);
    helper(paths, root->left, sum - root->val, so_far);
    helper(paths, root->right, sum - root->val, so_far);
}

std::vector<std::vector<int>> pathSum(TreeNode* root, int sum)
{
    std::vector<std::vector<int>> paths;
    helper(paths, root, sum, {});
    return paths;
}

int main()
{

}