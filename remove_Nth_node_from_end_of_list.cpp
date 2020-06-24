struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(0) {}
    ListNode(int x) : val(x), next(0) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    if(!head || n <= 0)
        return head;
    ListNode* curr = head;
    for(int i = 0; i <= n; i++)
    {
        if(curr)
            curr = curr->next;
        else
            return head->next;
    }
    
    ListNode* walk = head;
    while(curr)
    {
        walk = walk->next;
        curr = curr->next;
    }
    if(walk->next)
        walk->next = walk->next->next;
    return head;
}

int main()
{

}