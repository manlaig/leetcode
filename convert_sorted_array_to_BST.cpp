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

/*
    This solution uses divide and conquer
    In each function call, we create a new node with the middle element and its
    left branch is the height balanced tree from the left side, same for the right side
*/

TreeNode* sortedArrayToBST(std::vector<int>& nums, int start, int end)
{
    if(start > end)
        return 0;
    int mid = (start + end) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBST(nums, start, mid-1);
    root->right = sortedArrayToBST(nums, mid+1, end);
    return root;
}

int main()
{

}