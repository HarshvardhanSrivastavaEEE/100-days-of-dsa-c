#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node
{
    int data;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];

// queue
int queue[MAX];
int front = -1, rear = -1;

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int v)
{
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

void enqueue(int x)
{
    if(front == -1) front = 0;
    rear++;
    queue[rear] = x;
}

int dequeue()
{
    int x = queue[front];
    front++;
    return x;
}

int isEmpty()
{
    return front == -1 || front > rear;
}

void bfs(int start)
{
    enqueue(start);
    visited[start] = 1;

    while(!isEmpty())
    {
        int v = dequeue();
        printf("%d ", v);

        struct Node* temp = adj[v];
        while(temp != NULL)
        {
            if(!visited[temp->data])
            {
                enqueue(temp->data);
                visited[temp->data] = 1;
            }
            temp = temp->next;
        }
    }
}

int main()
{
    int n, e;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &e);

    int u, v;
    for(int i = 0; i < e; i++)
    {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    int start;
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    bfs(start);

    return 0;
}