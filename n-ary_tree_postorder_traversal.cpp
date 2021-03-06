#include <vector>

class Node
{
public:
    int val;
    std::vector<Node*> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, std::vector<Node*> _children)
    {
        val = _val;
        children = _children;
    }
};

void helper(std::vector<int>& out, Node* root)
{
    if(!root)
        return;
    for(Node* n : root->children)
        helper(out, n);
    out.push_back(root->val);
}

std::vector<int> postorder(Node* root)
{
    std::vector<int> out;
    helper(out, root);
    return out;
}

int main()
{
    
}