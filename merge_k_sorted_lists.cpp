#include <vector>
#include <queue>

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
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    ListNode* out = 0;
    ListNode** last = &out;
    int k = lists.size();
    for(int i = 0; i < k; i++)
    {
        while(lists[i])
        {
            q.push(lists[i]->val);
            lists[i] = lists[i]->next;
        }
    }
    
    while(q.size())
    {
        *last = new ListNode(q.top());
        q.pop();
        last = &((*last)->next);
    }
    return out;
}

ListNode* mergeKLists_slow(std::vector<ListNode*>& lists)
{
    // adding to 'last' will first initialize out, then will
    // be pointing to the end of the list
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
            *last = new ListNode((*min)->val);
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