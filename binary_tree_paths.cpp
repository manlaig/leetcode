#include <vector>
#include <string>
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

void helper(TreeNode* root, vector<string>& out, string curr)
{
    if(!root)
        return;
    if(!root->left && !root->right)
    {
        out.push_back(curr + to_string(root->val));
        return;
    }
    helper(root->left, out, curr + to_string(root->val) + "->");
    helper(root->right, out, curr + to_string(root->val) + "->");
}

vector<string> binaryTreePaths_recur(TreeNode* root)
{
    vector<string> out;
    helper(root, out, "");
    return out;
}

vector<string> binaryTreePaths(TreeNode* root)
{
    vector<string> out;
    if(!root)
        return out;
    stack<pair<TreeNode*, string> > s;
    s.push(make_pair(root, ""));
    
    while(s.size())
    {
        pair<TreeNode*, string> top = s.top();
        s.pop();
        
        string edited = top.second + "->" + to_string(top.first->val);
        if(top.first == root)
            edited = to_string(top.first->val);

        if(!top.first->left && !top.first->right)
            out.push_back(edited);
        if(top.first->left)
            s.push(make_pair(top.first->left, edited));
        if(top.first->right)
            s.push(make_pair(top.first->right, edited));
    }
    return out;
}

int main()
{

}