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

    int visited[100] = {0};
    int total = 0;

    visited[0] = 1;

    for(int edge = 0; edge < n - 1; edge++)
    {
        int min = INF;
        int a = -1, b = -1;

        for(int i = 0; i < n; i++)
        {
            if(visited[i] == 1)
            {
                for(int j = 0; j < n; j++)
                {
                    if(visited[j] == 0 && graph[i][j] != 0)
                    {
                        if(graph[i][j] < min)
                        {
                            min = graph[i][j];
                            a = i;
                            b = j;
                        }
                    }
                }
            }
        }

        visited[b] = 1;
        total = total + min;
    }

    printf("%d", total);

    return 0;
}