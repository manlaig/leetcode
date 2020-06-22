struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(0) {}
    ListNode(int x) : val(x), next(0) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void add(ListNode* head, ListNode*& add)
{
    ListNode** walk = &head;
    while(*walk)
        walk = &((*walk)->next);
    *walk = add;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    int carry = 0;
    ListNode* orig = l1;
    while(l1 && l2)
    {
        int temp = l1->val + l2->val + carry >= 10 ? 1 : 0;
        l1->val = (l1->val + carry + l2->val) % 10;
        carry = temp;
        l1 = l1->next;
        l2 = l2->next;
    }
    
    while(l1 && carry)
    {
        int temp = l1->val + carry >= 10 ? 1 : 0;
        l1->val = (l1->val + carry) % 10;
        l1 = l1->next;
        carry = temp;
    }
    
    if(l2)
    {
        ListNode* before = l2;
        while(l2 && carry)
        {
            int temp = l2->val + carry >= 10 ? 1 : 0;
            l2->val = (l2->val + carry) % 10;
            l2 = l2->next;
            carry = temp;
        }
        add(orig, before);
    }
        
    if(carry)
    {
        ListNode* temp = new ListNode(1);
        add(orig, temp);
    }
    return orig;
}

int main()
{

}