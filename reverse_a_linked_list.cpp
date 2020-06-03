struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(0) {}
    ListNode(int x) : val(x), next(0) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
    This problem is more intuitive if you draw it on a paper
    In each iteration, we are reversing ONE connection
*/

ListNode* reverseList(ListNode* head)
{
    if(!head)
        return head;
    
    // prev needs to 0, so in 1st iteration we can point head to null,
    // since the head node will be the tail of the linked list
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