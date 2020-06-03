struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(0) {}
    ListNode(int x) : val(x), next(0) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head)
{
    if(!head)
        return head;
    
    ListNode* prev = 0;
    ListNode* curr = head;
    
    while(curr)
    {
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

int main()
{

}