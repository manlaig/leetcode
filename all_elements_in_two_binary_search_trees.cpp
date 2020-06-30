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

void inorder(TreeNode* root, vector<int>& arr)
{
    if(!root)
        return;
    inorder(root->left, arr);
    arr.push_back(root->val);
    inorder(root->right, arr);
}

vector<int> merge(const vector<int>& a1, const vector<int>& a2)
{
    vector<int> out;
    out.reserve(a1.size() + a2.size());
    
    int i1 = 0, i2 = 0;
    while(i1 < a1.size() && i2 < a2.size())
    {
        if(a1[i1] < a2[i2])
            out.push_back(a1[i1++]);
        else
            out.push_back(a2[i2++]);
    }
    while(i1 < a1.size())
        out.push_back(a1[i1++]);
    while(i2 < a2.size())
        out.push_back(a2[i2++]);
    
    return out;
}

vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
{
    vector<int> arr, arr2;
    arr.reserve(25);
    arr2.reserve(25);
    
    inorder(root1, arr);
    inorder(root2, arr2);
    
    return merge(arr, arr2);
}

int main()
{

}