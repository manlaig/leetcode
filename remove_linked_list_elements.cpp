struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeElements(ListNode* head, int val)
{
    ListNode** walk = &head;
    while(*walk)
    {
        if((*walk)->val == val)
            *walk = (*walk)->next;
        else
            walk = &((*walk)->next);
    }
    return head;
}

int main()
{
    
}