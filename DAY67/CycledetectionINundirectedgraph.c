#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int visited[MAX];
int adj[MAX][MAX]; // adjacency matrix
int V;

// DFS function
int dfs(int node, int parent)
{
    visited[node] = 1;

    for(int i = 0; i < V; i++)
    {
        if(adj[node][i])
        {
            if(!visited[i])
            {
                if(dfs(i, node))
                    return 1;
            }
            else if(i != parent)
            {
                return 1; // cycle found
            }
        }
    }
    return 0;
}

int main()
{
    int E;
    printf("Enter number of vertices and edges:\n");
    scanf("%d %d", &V, &E);

    // initialize
    for(int i = 0; i < V; i++)
    {
        visited[i] = 0;
        for(int j = 0; j < V; j++)
            adj[i][j] = 0;
    }

    printf("Enter edges (u v):\n");
    for(int i = 0; i < E; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // undirected
    }

    int cycle = 0;

    for(int i = 0; i < V; i++)
    {
        if(!visited[i])
        {
            if(dfs(i, -1))
            {
                cycle = 1;
                break;
            }
        }
    }

    if(cycle)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}