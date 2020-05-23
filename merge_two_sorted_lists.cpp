/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    
    void addRest(ListNode*& lst, ListNode* from)
    {
        while(from)
        {
            lst->next = new ListNode(from->val);
            lst = lst->next;
            from = from->next;
        }
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode* lst = new ListNode, *curr = lst;
        
        while(l1 && l2)
        {
            ListNode* temp = new ListNode;
            if(l1->val < l2->val)
            {
                temp->val = l1->val;
                l1 = l1->next;
            }
            else
            {
                temp->val = l2->val;
                l2 = l2->next;
            }
            curr->next = temp;
            curr = curr->next;
        }
        
        addRest(curr, l1);
        addRest(curr, l2);
        
        ListNode* out = lst->next;
        delete lst;
        return out;
    }
};