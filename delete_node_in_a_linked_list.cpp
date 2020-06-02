struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(0) {}
};

void deleteNode(ListNode* node)
{
    while(node->next->next)
    {
        node->val = node->next->val;
        node = node->next;
    }
    node->val = node->next->val;
    node->next = 0;
}

int main()
{
    
}