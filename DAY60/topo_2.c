#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int indegree[MAX];
int queue[MAX];
int front = 0, rear = -1;

int main()
{
    int n, e;
    int u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    for(int i = 0; i < n; i++)
    {
        indegree[i] = 0;
        for(int j = 0; j < n; j++)
        {
            adj[i][j] = 0;
        }
    }

    printf("Enter edges u v, meaning u -> v:\n");
    for(int i = 0; i < e; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }

    for(int i = 0; i < n; i++)
    {
        if(indegree[i] == 0)
        {
            rear++;
            queue[rear] = i;
        }
    }

    int count = 0;

    printf("Topological Sort: ");

    while(front <= rear)
    {
        int current = queue[front];
        front++;

        printf("%d ", current);
        count++;

        for(int i = 0; i < n; i++)
        {
            if(adj[current][i] == 1)
            {
                indegree[i]--;

                if(indegree[i] == 0)
                {
                    rear++;
                    queue[rear] = i;
                }
            }
        }
    }

    if(count != n)
    {
        printf("\nCycle detected! Topological sort not possible.");
    }

    return 0;
}