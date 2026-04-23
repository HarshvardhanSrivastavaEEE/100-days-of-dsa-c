int main()
{
    int vertices = 4;

    struct Node* graph[vertices];
    for(int i = 0; i < vertices; i++)
    {
        graph[i] = NULL;
    }

    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    if(hasCycle(graph, vertices))
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}