#include <stdio.h>
#include <stdlib.h>

struct node
{
    int vertex;
    struct node* next;
};

struct node* create_node(int v)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->vertex = v;
    new_node->next = NULL;
    return new_node;
}

int main()
{
    int n, m;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    struct node* adj[n];

    for(int i = 0; i < n; i++)
    {
        adj[i] = NULL;
    }

    int u, v;

    printf("Enter edges (u v):\n");
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);

        struct node* new_node = create_node(v);
        new_node->next = adj[u];
        adj[u] = new_node;

        new_node = create_node(u);
        new_node->next = adj[v];
        adj[v] = new_node;
    }

    printf("\nAdjacency List:\n");

    for(int i = 0; i < n; i++)
    {
        printf("%d -> ", i);
        struct node* temp = adj[i];
        while(temp != NULL)
        {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }

    return 0;
}