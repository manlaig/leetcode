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

int main()
{

}