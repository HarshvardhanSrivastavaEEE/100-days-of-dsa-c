#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct QueueNode
{
    struct TreeNode *tree_node;
    struct QueueNode *next;
};

struct Queue
{
    struct QueueNode *front;
    struct QueueNode *rear;
    int size;
};

struct TreeNode *create_node(int value)
{
    struct TreeNode *new_node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void init_queue(struct Queue *q)
{
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

int is_queue_empty(struct Queue *q)
{
    return q->front == NULL;
}

void enqueue(struct Queue *q, struct TreeNode *node)
{
    struct QueueNode *new_qnode = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    new_qnode->tree_node = node;
    new_qnode->next = NULL;

    if (q->rear == NULL)
    {
        q->front = new_qnode;
        q->rear = new_qnode;
    }
    else
    {
        q->rear->next = new_qnode;
        q->rear = new_qnode;
    }

    q->size++;
}

struct TreeNode *dequeue(struct Queue *q)
{
    if (is_queue_empty(q))
    {
        return NULL;
    }

    struct QueueNode *temp = q->front;
    struct TreeNode *node = temp->tree_node;

    q->front = q->front->next;
    if (q->front == NULL)
    {
        q->rear = NULL;
    }

    free(temp);
    q->size--;
    return node;
}

struct TreeNode *build_tree(int arr[], int n)
{
    if (n == 0 || arr[0] == -1)
    {
        return NULL;
    }

    struct TreeNode *root = create_node(arr[0]);
    struct Queue q;
    init_queue(&q);
    enqueue(&q, root);

    int i = 1;

    while (i < n && !is_queue_empty(&q))
    {
        struct TreeNode *current = dequeue(&q);

        if (i < n && arr[i] != -1)
        {
            current->left = create_node(arr[i]);
            enqueue(&q, current->left);
        }
        i++;

        if (i < n && arr[i] != -1)
        {
            current->right = create_node(arr[i]);
            enqueue(&q, current->right);
        }
        i++;
    }

    return root;
}

void zigzag_traversal(struct TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    struct Queue q;
    init_queue(&q);
    enqueue(&q, root);

    int left_to_right = 1;

    while (!is_queue_empty(&q))
    {
        int level_size = q.size;
        int level_nodes[level_size];

        for (int i = 0; i < level_size; i++)
        {
            struct TreeNode *current = dequeue(&q);

            int index;
            if (left_to_right)
            {
                index = i;
            }
            else
            {
                index = level_size - 1 - i;
            }

            level_nodes[index] = current->data;

            if (current->left != NULL)
            {
                enqueue(&q, current->left);
            }

            if (current->right != NULL)
            {
                enqueue(&q, current->right);
            }
        }

        for (int i = 0; i < level_size; i++)
        {
            printf("%d ", level_nodes[i]);
        }

        left_to_right = !left_to_right;
    }
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

    struct TreeNode *root = build_tree(arr, n);
    zigzag_traversal(root);

    return 0;
}