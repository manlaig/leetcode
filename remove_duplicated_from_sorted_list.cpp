struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head)
{
    if(!head)
        return head;
    ListNode *prev = head, *walk = head->next;
    
    while(walk)
    {
        if(walk->val == prev->val)
        {
            prev->next = walk->next;
            if(!prev)
                break;
            walk = prev->next;
        }
        else
        {    
            prev = walk;
            walk = walk->next;
        }
    }
    
    return head;
}