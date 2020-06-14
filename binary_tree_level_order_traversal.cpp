#include <vector>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(0), right(0) {}
    TreeNode(int x) : val(x), left(0), right(0) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int getHeight(TreeNode* root)
{
    return !root ? 0 : max(getHeight(root->left), getHeight(root->right)) + 1;
}

vector<vector<int>> levelOrder(TreeNode* root)
{
    if(!root)
        return {};
    int depth = getHeight(root);
    vector<vector<int>> out(depth);
    stack<pair<TreeNode*, int>> s;
    
    s.push(make_pair(root, 0));
    while(s.size())
    {
        pair<TreeNode*, int> top = s.top();
        s.pop();
        
        out[top.second].push_back(top.first->val);
        
        if(top.first->right)
            s.push(make_pair(top.first->right, top.second+1));
        if(top.first->left)
            s.push(make_pair(top.first->left, top.second+1));
    }
    return out;
}

int main()
{

}