#include <vector>
#include <stack>
#include <set>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(0), right(0) {}
    TreeNode(int x) : val(x), left(0), right(0) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::vector<int> inorderTraversal(TreeNode* root)
{
    std::vector<int> out;
    std::stack<TreeNode*> s;
    std::set<TreeNode*> visited;

    if(root)
        s.push(root);
    
    while(s.size())
    {
        TreeNode* top = s.top();
        s.pop();
        
        if(top->left && visited.find(top->left) == visited.end())
        {
            s.push(top);
            s.push(top->left);
        }
        else
        {
            visited.insert(top);
            out.push_back(top->val);
            if(top->right && visited.find(top->right) == visited.end())
                s.push(top->right);
        }
    }
    
    return out;
}

int main()
{
    
}