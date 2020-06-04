#include <iostream>
#include <stack>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(0), right(0) {}
    TreeNode(int x) : val(x), left(0), right(0) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// this approach uses tree recursion
int maxDepth_recur(TreeNode* root, int depth = 0)
{
    if(!root)
        return depth;
    return std::max(maxDepth_recur(root->left, depth + 1), maxDepth_recur(root->right, depth + 1));
}

// this approach uses DFS
int maxDepth_iter(TreeNode* root, int depth = 0)
{
    int max = 0;

    // s stores a pointer and how far deep it has gone so far (current depth at that node)
    std::stack<std::pair<TreeNode*, int> > s;
    if(root)
        s.push(std::make_pair(root, 1));
    
    while(!s.empty())
    {
        std::pair<TreeNode*,int> p = s.top();
        s.pop();
        
        if(p.first->left)
            s.push(std::make_pair(p.first->left, p.second + 1));
        if(p.first->right)
            s.push(std::make_pair(p.first->right, p.second + 1));
        // this condition being true means the above 2 is false
        if(!p.first->left && !p.first->right && p.second > max)
            max = p.second;
    }
    return max;
}

int main()
{

}