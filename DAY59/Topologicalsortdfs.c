#include <stdio.h>
#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int V = 6;

void dfs(int v)
{
    visited[v] = 1;

    for(int i = 0; i < V; i++)
    {
        if(graph[v][i] == 1 && visited[i] == 0)
        {
            dfs(i);
        }
    }

    top++;
    stack[top] = v;
}

int main()
{
    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            graph[i][j] = 0;
        }
        visited[i] = 0;
    }

    graph[5][2] = 1;
    graph[5][0] = 1;
    graph[4][0] = 1;
    graph[4][1] = 1;
    graph[2][3] = 1;
    graph[3][1] = 1;

    for(int i = 0; i < V; i++)
    {
        if(visited[i] == 0)
        {
            dfs(i);
        }
    }

    printf("Topological Sort:\n");
    while(top != -1)
    {
        printf("%d ", stack[top]);
        top--;
    }

    return 0;
}