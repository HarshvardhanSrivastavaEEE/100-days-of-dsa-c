#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Queue
{
    struct Node** arr;
    int front;
    int rear;
};

struct Node* create_node(int value)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct Queue* create_queue(int size)
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->arr = (struct Node**)malloc(size * sizeof(struct Node*));
    q->front = 0;
    q->rear = -1;
    return q;
}

int is_empty(struct Queue* q)
{
    return q->front > q->rear;
}

void enqueue(struct Queue* q, struct Node* node)
{
    q->rear++;
    q->arr[q->rear] = node;
}

struct Node* dequeue(struct Queue* q)
{
    struct Node* temp = q->arr[q->front];
    q->front++;
    return temp;
}

struct Node* build_tree(int arr[], int n)
{
    if (n == 0 || arr[0] == -1)
    {
        return NULL;
    }

    struct Node* root = create_node(arr[0]);
    struct Queue* q = create_queue(n);
    enqueue(q, root);

    int i = 1;

    while (i < n && !is_empty(q))
    {
        struct Node* current = dequeue(q);

        if (i < n && arr[i] != -1)
        {
            current->left = create_node(arr[i]);
            enqueue(q, current->left);
        }
        i++;

        if (i < n && arr[i] != -1)
        {
            current->right = create_node(arr[i]);
            enqueue(q, current->right);
        }
        i++;
    }

    free(q->arr);
    free(q);

    return root;
}

void mirror_tree(struct Node* root)
{
    if (root == NULL)
    {
        return;
    }

    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror_tree(root->left);
    mirror_tree(root->right);
}

void inorder(struct Node* root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    struct Node* root = build_tree(arr, n);
    mirror_tree(root);
    inorder(root);

    return 0;
}