#include <iostream>

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
    In tree problems, I often come up with recursive solutions. They can be converted to iterative approaches,
    but recursive solutions are more straightforward to implement. To come up with a recursive solution,
    it's important to see the problem as many subproblems

    For example, we know the longest may or may not pass through the root node, so that means the longest path is
    in either left or right branches or it passed through the root. In that case where it passes through,
    the length of it is the height sum of the left and right branches.

    The complexity of this solution is O(NlogN) time and O(logN) space.
    We visit each node and get the height at each node, that results in O(NlogN)
    We allocate O(logN) space because the call stack of the left branch call is destroyed before the right branch call.
*/

int getHeight(TreeNode* root)
{
    if(!root)
        return 0;
    return std::max(getHeight(root->left), getHeight(root->right)) + 1;
}

int diameterOfBinaryTree(TreeNode* root)
{
    if(!root)
        return 0;
    int left = getHeight(root->left);
    int right = getHeight(root->right);
    return std::max(left + right, std::max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
}

int main()
{

}