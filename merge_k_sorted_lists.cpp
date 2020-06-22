#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(0) {}
    ListNode(int x) : val(x), next(0) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void add(ListNode*& head, int val)
{
    ListNode** walk = &head;
    while(*walk)
        walk = &((*walk)->next);
    *walk = new ListNode(val);
}

ListNode* mergeKLists(std::vector<ListNode*>& lists)
{
    ListNode* out = 0;
    int k = lists.size();
    
    while(1)
    {
        ListNode** min = 0;
        for(int i = 0; i < k; i++)
        {
            if(lists[i])
            {
                if(min == 0 || (*min)->val > lists[i]->val)
                    min = &lists[i];
            }
        }
        if(min)
        {
            add(out, (*min)->val);
            *min = (*min)->next;
        }
        else
            break;
    }
    return out;
}

int main()
{

}