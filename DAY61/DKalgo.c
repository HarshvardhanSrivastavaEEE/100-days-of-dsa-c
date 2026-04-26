#include <stdio.h>
#include <limits.h>

#define V 5
#define INF 999999

int minDistance(int dist[], int visited[])
{
    int min = INF;
    int index = -1;

    for(int i = 0; i < V; i++)
    {
        if(visited[i] == 0 && dist[i] < min)
        {
            min = dist[i];
            index = i;
        }
    }

    return index;
}

void dijkstra(int graph[V][V], int source)
{
    int dist[V];
    int visited[V];

    for(int i = 0; i < V; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[source] = 0;

    for(int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, visited);

        if(u == -1)
            break;

        visited[u] = 1;

        for(int v = 0; v < V; v++)
        {
            if(visited[v] == 0 && graph[u][v] != 0 &&
               dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Vertex\tShortest Distance from Source\n");

    for(int i = 0; i < V; i++)
    {
        printf("%d\t%d\n", i, dist[i]);
    }
}

int main()
{
    int graph[V][V] =
    {
        {0, 10, 0, 5, 0},
        {0, 0, 1, 2, 0},
        {0, 0, 0, 0, 4},
        {0, 3, 9, 0, 2},
        {7, 0, 6, 0, 0}
    };

    int source = 0;

    dijkstra(graph, source);

    return 0;
}