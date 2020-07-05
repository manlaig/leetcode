#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(0) {}
    ListNode(int x) : val(x), next(0) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isPalindrome(ListNode* head)
{
    std::vector<int> vec;
    vec.reserve(16);    // just to avoid resizing often
    while(head)
    {
        vec.push_back(head->val);
        head = head->next;
    }
    int start = 0;
    int end = vec.size() - 1;
    while(start < end)
    {
        if(vec[start] != vec[end])
            return false;
        start++;
        end--;
    }
    return true;
}

// you can also create a new list, which is the reverse of the original
// and check if each element matches
bool isPalindrome_reverse(ListNode* head)
{
    if(!head || !head->next)
        return true;
    ListNode *rev = new ListNode(head->val, head->next), *prev = 0;
    
    while(rev)
    {
        ListNode* temp = rev->next;
        rev->next = prev;
        prev = rev;
        rev = temp;
        if(temp)
            rev = new ListNode(temp->val, temp->next);
    }
    while(prev && head)
    {
        if(prev->val != head->val)
            return false;
        prev = prev->next;
        head = head->next;
    }
    return true;
}

int main()
{

}