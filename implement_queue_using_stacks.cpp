#include <stack>

class MyQueue
{
    std::stack<int> s1, s2;
public:
    /** Initialize your data structure here. */
    MyQueue() {}
    
    /** Push element x to the back of queue. */
    void push(int x)
    {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        while(s1.size() > 1)
        {
            s2.push(s1.top());
            s1.pop();
        }
        int ret = s1.top();
        s1.pop();
        while(s2.size())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return ret;
    }
    
    /** Get the front element. */
    int peek()
    {
        int ret = 0;
        while(s1.size())
        {
            ret = s1.top();
            s2.push(ret);
            s1.pop();
        }
        while(s2.size())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return ret;
    }
    
    /** Returns whether the queue is empty. */
    bool empty()
    {
        return s1.empty();
    }
};

int main()
{

}