struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(0) {}
};

bool hasCycle(ListNode *head)
{
    if(!head)
        return false;
    ListNode* fast = head->next;
    ListNode* slow = head;
    
    while(fast)
    {
        if(fast == slow)
            return true;
        fast = fast->next;
        if(!fast)
            break;
        if(fast == slow)
            return true;
        fast = fast->next;
        if(!fast)
            break;
        if(fast == slow)
            return true;
        fast = fast->next;
        slow = slow->next;
    }
    return false;
}

int main()
{
    
}