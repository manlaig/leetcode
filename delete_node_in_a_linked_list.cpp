struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(0) {}
};

void deleteNode(ListNode* node)
{
    /*
        we aren't given the head, plus the pointer's not passed by reference
        and the function returns void, so we have "propagate" the values
        
                delete 4
                    V
        1->2->3->4->5->6->7
            loop condition stops here
                        V    
        1->2->3->5->6->6->7
            the outer loop copies the last value and deletes the last
        1->2->3->5->6->7
        
    */
   
    /*
    // 1st option
    while(node->next->next)
    {
        node->val = node->next->val;
        node = node->next;
    }
    node->val = node->next->val;
    node->next = 0;
    */

    // 2nd option
    ListNode* prev = node;
    while(node->next)
    {
        // to access node->next->val, loop condition must be node->next
        node->val = node->next->val;
        prev = node;
        node = node->next;
    }
    prev->next = 0;
}

int main()
{
    
}