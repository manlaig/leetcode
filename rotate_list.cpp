struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(0) {}
    ListNode(int x) : val(x), next(0) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* rotateRight(ListNode* head, int k)
{
    if(!head)
        return head;
    
    ListNode* curr = head;
    int size = 0;
    while(curr)
    {
        size++;
        curr = curr->next;
    }
    k = k % size;
    if(!k)
        return head;
    
    curr = head;
    for(int i = 0; i < k; i++)
    {
        curr = curr->next;
    }
    
    ListNode* back = head;
    while(curr->next)
    {
        back = back->next;
        curr = curr->next;
    }
    ListNode* temp = head;
    head = back->next;
    back->next = 0;
    curr->next = temp;
    return head;
}

int main()
{

}