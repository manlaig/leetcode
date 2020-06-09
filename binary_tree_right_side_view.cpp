#include <vector>
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

/*
    Compile with C++11
    You can also you DFS for this problem, the DFS solution is below
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

vector<int> DFS(TreeNode* root)
{
    if(!root)
        return {};
    
    vector<int> out;
    int most = -1;
    stack<pair<TreeNode*, int>> next;
    next.push(make_pair(root, 0));

    while(next.size())
    {
        auto p = next.top();
        next.pop();

        TreeNode* curr = p.first;
        if(p.second > most)
        {
            most = p.second;
            out.push_back(curr->val);
        }

        if(curr->left)
            next.push(make_pair(curr->left, p.second+1));
        if(curr->right)
            next.push(make_pair(curr->right, p.second+1));
    }
    return out;
}

int main()
{

}