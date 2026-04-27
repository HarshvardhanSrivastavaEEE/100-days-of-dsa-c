#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF 999999

struct Edge
{
    int u;
    int v;
    int w;
};

int main()
{
    int n, m, source;
    struct Edge edges[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter edges (u v w):\n");
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    int dist[MAX];

    for(int i = 0; i < n; i++)
    {
        dist[i] = INF;
    }

    dist[source] = 0;

    for(int i = 1; i <= n - 1; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if(dist[u] != INF && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    int negativeCycle = 0;

    for(int j = 0; j < m; j++)
    {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if(dist[u] != INF && dist[u] + w < dist[v])
        {
            negativeCycle = 1;
            break;
        }
    }

    if(negativeCycle)
    {
        printf("NEGATIVE CYCLE\n");
    }
    else
    {
        printf("Shortest distances from source %d:\n", source);

        for(int i = 0; i < n; i++)
        {
            if(dist[i] == INF)
            {
                printf("%d -> INF\n", i);
            }
            else
            {
                printf("%d -> %d\n", i, dist[i]);
            }
        }
    }

    return 0;
}