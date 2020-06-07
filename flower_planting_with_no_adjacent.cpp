#include <vector>
#include <queue>
using namespace std;

//////////////////////////// Data Structures BEGIN ////////////////////////////
struct Node
{
    Node* next;
    int val;
    Node(int v) : val(v), next(0) {}
    Node(int v, Node* n) : next(n), val(v) {}
};

namespace LL
{
    inline void addToHead(Node*& head, int val)
    {
        head = new Node(val, head);
    }

    // we can also have a wrapper class containing both head and tail
    void addToTail(Node*& head, int val)
    {
        Node** walk = &head;
        while(*walk)
            walk = &((*walk)->next);
        *walk = new Node(val);
    }
}

class Graph
{
public:
    // array of node pointers
    Node* *arr;
    int size;
    Graph(int vertices);
    ~Graph();
    void addDirected(int from, int to);
    void addUndirected(int from, int to);
};

Graph::Graph(int vertices) : arr(new Node*[vertices]), size(vertices)
{
    for(int i = 0; i < vertices; i++)
        arr[i] = 0;
}

Graph::~Graph()
{
    for(int i = 0; i < size; i++)
    {
        while(arr[i])
        {
            Node* temp = arr[i]->next;
            delete arr[i];
            arr[i] = temp;
        }
    }
}

// doesn't check if the edge already exists
void Graph::addDirected(int from, int to)
{
    LL::addToTail(arr[from], to);
}

//////////////////////////// Data Structures END ////////////////////////////

/*
    Given that there's isn't an edge to itself, we don't have to keep a "visited" set
    Then, how do we know that the algorithm will terminate?
*/
void bfs(vector<int>& flowers, const Graph& garden)
{
    queue<int> next;

    // the graph can be disconnected, so add them all here
    for(int i = 0; i < garden.size; i++)
        next.push(i);

    while(next.size())
    {
        int i = next.front();
        next.pop();

        // looping through all neighbors of i
        Node* head = garden.arr[i];
        while(head)
        {
            if(flowers[head->val] == flowers[i])
            {
                flowers[head->val] = flowers[head->val] % 4 + 1;
                next.push(head->val);
            }
            head = head->next;
        }
    }
}

vector<int> gardenNoAdj(int N, const vector<vector<int>>& paths)
{
    Graph garden(N);
    vector<int> flowers(N);

    for(int i = 0; i < N; i++)
        flowers[i] = 1;

    for(const vector<int>& edge : paths)
        garden.addUndirected(edge[0]-1, edge[1]-1);

    bfs(flowers, garden);

    return flowers;
}

int main()
{
    
}