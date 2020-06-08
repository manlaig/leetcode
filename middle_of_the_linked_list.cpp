struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(0) {}
    ListNode(int x) : val(x), next(0) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* middleNode(ListNode* head)
{
    ListNode *p1 = head, *p2 = head;
    
    while(p2)
    {
        p2 = p2->next;
        if(!p2)
            return p1;
        p1 = p1->next;
        p2 = p2->next;
        if(!p2)
            return p1;
    }
    return 0;
}

int main()
{
    
}