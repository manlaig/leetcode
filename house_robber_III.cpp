#include <unordered_map>
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

class Solution
{
    // for using a pair as a key for the map
    struct hash_pair
    { 
        template <class T1, class T2> 
        size_t operator()(const pair<T1, T2>& p) const
        { 
            auto hash1 = hash<T1>{}(p.first); 
            auto hash2 = hash<T2>{}(p.second); 
            return hash1 ^ hash2; 
        } 
    }; 
public:

    int startRobbing(TreeNode* root, bool rob, unordered_map<pair<TreeNode*, bool>, int, hash_pair>& dp)
    {
        if(!root)
            return 0;
        
        pair<TreeNode*, bool> p = make_pair(root, rob);

        if(dp.find(p) != dp.end())
            return dp[p];
            
        int amount = rob ? root->val : 0;
        dp[p] = max(amount + startRobbing(root->left, false, dp) + startRobbing(root->right, false, dp),
                             startRobbing(root->left, true, dp) + startRobbing(root->right, true, dp));
        return dp[p];
    }
    
    int rob(TreeNode* root)
    {
        unordered_map<pair<TreeNode*, bool>, int, hash_pair> dp;
        return std::max(startRobbing(root, true, dp),startRobbing(root, false, dp));
    }
};