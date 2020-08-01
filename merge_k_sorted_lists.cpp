#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(0) {}
    ListNode(int x) : val(x), next(0) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeKLists(std::vector<ListNode*>& lists)
{
    ListNode* out = 0;
    ListNode** last = &out;
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
            auto temp = new ListNode((*min)->val);
            *last = temp;
            last = &((*last)->next);
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