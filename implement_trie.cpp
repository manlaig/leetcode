#include <vector>
#include <string>
using namespace std;

class Trie {
    struct Node
    {
        char val = ' ';
        vector<Node*> children;
        bool end;
        Node() : children(vector<Node*>(26)), end(false)
        {
            
        }
    } *head;
public:
    /** Initialize your data structure here. */
    Trie() : head(new Node()) {}
    
    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Node* curr = head;
        for(char c : word)
        {
            if(!curr->children[c - 'a'])
            {
                Node* temp = new Node();
                temp->val = c;
                curr->children[c - 'a'] = temp;
                curr = temp;
            }
            else
            {
                curr = curr->children[c - 'a'];
            }
        }
        curr->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Node* curr = head;
        for(char c : word)
        {
            if(curr->children[c - 'a'])
            {
                curr = curr->children[c - 'a'];
            }
            else
                return false;
        }
        return curr->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        Node* curr = head;
        for(char c : prefix)
        {
            if(curr->children[c - 'a'])
            {
                curr = curr->children[c - 'a'];
            }
            else
                return false;
        }
        return curr != 0;
    }
};

int main()
{

}