struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(0) {}
};

/*
    we can also use a hash table to solve this problem
    You can use a hash table to find cycles in a LL and intersections between LLs
    The time complexity of both is O(n) where n = number of nodes
*/

bool hasCycle(ListNode *head)
{
    // because of how fast is defined, we need to have this check here
    if(!head)
        return false;
    
    // fast = head->next because if they're the same,
    // then we immediate have a cycle (by how our algorithm works)
    ListNode* fast = head->next;
    ListNode* slow = head;

    // you can also do it like this, but this loop only advances 2 steps in each iteration
    // so this one can be slower, even though the code is shorter
    /*
    while(fast != slow)
    {
        if(!fast || !fast->next)
            return false;
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
    */
    
    // fast is always ahead, fast is null BEFORE slow is null
    // the reason this loop is faster than the one above is because it "unrolls" the loop
    while(fast)
    {
        // unfortunately, since fast moves multiple times each iteration,
        // we need to have multiple checks, modularizing wouldn't help much
        if(fast == slow)
            return true;
        fast = fast->next;
        if(!fast)
            break;
        if(fast == slow)
            return true;
        fast = fast->next;
        if(!fast)
            break;
        if(fast == slow)
            return true;
        fast = fast->next;
        slow = slow->next;
    }
    return false;
}

int main()
{
    
}