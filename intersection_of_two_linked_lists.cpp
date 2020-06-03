#include <set>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(0) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if(!headA || !headB)
        return 0;
    std::set<ListNode*> visited;
    while(headA)
    {
        visited.insert(headA);
        headA = headA->next;
    }
    while(headB)
    {
        if(visited.find(headB) != visited.end())
            return headB;
        headB = headB->next;
    }
    return 0;
}

int main()
{
    
}