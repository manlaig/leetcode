#include <queue>

class MyStack
{
    std::queue<int> q1, q2;
public:
    /** Initialize your data structure here. */
    MyStack() {}
    
    /** Push element x onto stack. */
    void push(int x)
    {
        q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        if(q1.empty())
            return -1;
        while(q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int ret = q1.front();
        q1.pop();
        while(q2.size())
        {
            q1.push(q2.front());
            q2.pop();
        }
        return ret;
    }
    
    /** Get the top element. */
    int top()
    {
        if(q1.empty())
            return -1;
        int ret = 0;
        while(q1.size())
        {
            ret = q1.front();
            q2.push(ret);
            q1.pop();
        }
        while(q2.size())
        {
            q1.push(q2.front());
            q2.pop();
        }
        return ret;
    }
    
    /** Returns whether the stack is empty. */
    bool empty()
    {
        return q1.empty();
    }
};

int main()
{

}