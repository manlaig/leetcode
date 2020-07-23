#include <iostream>
#include <vector>

class Node
{
public:
    int val;
    std::vector<Node*> children;

    Node() {}

    Node(int _val) : val(_val) {}

    Node(int _val, std::vector<Node*> _children)
    {
        val = _val;
        children = _children;
    }
};

int maxDepth(Node* root)
{
    if(!root)
        return 0;
    int out = 1;
    for(Node* child : root->children)
    {
        out = std::max(out, maxDepth(child)+1);
    }
    return out;
}

int main()
{

}