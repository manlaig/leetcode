#include <iostream>

class MinStack
{
    struct Node
    {
        Node* next;
        int val, smallest;
        Node(int v, int s, Node* head) : next(head), val(v), smallest(s) {}
    } *head;
    
public:
    /** initialize your data structure here. */
    MinStack()
    {
        head = 0;
    }
    
    void push(int val)
    {
        head = new Node(val, std::min(head ? head->smallest : val, val), head);
    }
    
    void pop()
    {
        if(!head)
            return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    int top()
    {
        return head->val;
    }
    
    int getMin()
    {
        return head->smallest;
    }
};

int main()
{

}