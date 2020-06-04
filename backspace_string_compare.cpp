#include <string>
#include <stack>

bool backspaceCompare(std::string S, std::string T)
{
    std::stack<int> st, st2;
    int size = std::max(S.size(), T.size());
    for(int i = 0; i < size; i++)
    {
        if(i < S.size())
        {
            if(S[i] != '#')
                st.push(S[i]);
            else if(st.size())
                st.pop();
        }
        if(i < T.size())
        {
            if(T[i] != '#')
                st2.push(T[i]);
            else if(st2.size())
                st2.pop();
        }
    }
    if(st.size() != st2.size())
        return false;
    while(st.size())
    {
        if(st.top() != st2.top())
            return false;
        st.pop();
        st2.pop();
    }
    return true;
}

int main()
{
    
}