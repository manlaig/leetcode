struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(0) {}
    ListNode(int x) : val(x), next(0) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* oddEvenList(ListNode* head)
{
    if(!head || !head->next)
        return head;
    ListNode* start = head;
    ListNode* next = head->next;
    
    while(next && next->next)
    {
        ListNode* t = next->next->next;
        next->next->next = start->next;
        ListNode* temp = start->next;
        start->next = next->next;
        start = start->next;
        next->next = t;
        next = t;
    }
    
    return head;
}

int main()
{
    
}