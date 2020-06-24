struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(0) {}
    ListNode(int x) : val(x), next(0) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// the idea is that we have 1 pointer ahead of the other one by 1 nodes
// when the leading one reaches the end, then 
// it means that the other one is at the Nth node from the end
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