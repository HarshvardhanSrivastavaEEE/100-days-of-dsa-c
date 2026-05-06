#include <stdio.h>

#define INF 999999

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[100][100];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        u--;
        v--;

        graph[u][v] = w;
        graph[v][u] = w;
    }

    int source;
    scanf("%d", &source);
    source--;

    int dist[100];
    int visited[100] = {0};

    for(int i = 0; i < n; i++)
    {
        dist[i] = INF;
    }

    dist[source] = 0;

    for(int count = 0; count < n - 1; count++)
    {
        int min = INF;
        int u = -1;

        for(int i = 0; i < n; i++)
        {
            if(visited[i] == 0 && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        for(int v = 0; v < n; v++)
        {
            if(visited[v] == 0 && graph[u][v] != 0)
            {
                if(dist[u] + graph[u][v] < dist[v])
                {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        printf("%d ", dist[i]);
    }

    return 0;
}