#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* create_node(int value)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if(new_node == NULL)
    {
        return NULL;
    }
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

int length_list(struct Node* head)
{
    int len = 0;
    while(head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}

struct Node* get_intersection_node(struct Node* head1, struct Node* head2)
{
    int len1 = length_list(head1);
    int len2 = length_list(head2);

    int diff = len1 - len2;
    if(diff < 0) diff = -diff;

    /* move pointer in longer list by diff */
    if(len1 > len2)
    {
        while(diff--)
        {
            head1 = head1->next;
        }
    }
    else
    {
        while(diff--)
        {
            head2 = head2->next;
        }
    }

    /* now move both together */
    while(head1 != NULL && head2 != NULL)
    {
        if(head1 == head2)
        {
            return head1;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
}

struct Node* build_shared_suffix(int arr[], int start, int n)
{
    struct Node* head = NULL;
    struct Node* tail = NULL;

    for(int i = start; i < n; i++)
    {
        struct Node* new_node = create_node(arr[i]);
        if(new_node == NULL) return NULL;

        if(head == NULL)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
    }
    return head;
}

struct Node* build_prefix_and_attach(int arr[], int n, int prefix_len, struct Node* attach)
{
    struct Node* head = NULL;
    struct Node* tail = NULL;

    for(int i = 0; i < prefix_len; i++)
    {
        struct Node* new_node = create_node(arr[i]);
        if(new_node == NULL) return NULL;

        if(head == NULL)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
    }

    if(head == NULL)
    {
        /* no prefix, list starts from shared part */
        return attach;
    }

    tail->next = attach;
    return head;
}

int main()
{
    int n, m;

    scanf("%d", &n);
    int* a = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    scanf("%d", &m);
    int* b = (int*)malloc(m * sizeof(int));
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }

    /* find common suffix length based on values */
    int i = n - 1;
    int j = m - 1;
    int common = 0;

    while(i >= 0 && j >= 0 && a[i] == b[j])
    {
        common++;
        i--;
        j--;
    }

    struct Node* shared = NULL;
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    if(common > 0)
    {
        int start_shared = n - common;
        shared = build_shared_suffix(a, start_shared, n);

        head1 = build_prefix_and_attach(a, n, n - common, shared);
        head2 = build_prefix_and_attach(b, m, m - common, shared);
    }
    else
    {
        /* no shared part at all */
        head1 = build_prefix_and_attach(a, n, n, NULL);
        head2 = build_prefix_and_attach(b, m, m, NULL);
    }

    struct Node* ans = get_intersection_node(head1, head2);

    if(ans == NULL)
    {
        printf("No Intersection");
    }
    else
    {
        printf("%d", ans->data);
    }

    free(a);
    free(b);

    return 0;
}