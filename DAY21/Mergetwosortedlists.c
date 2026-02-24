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
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

void display_list(struct Node* head)
{
    struct Node* temp = head;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node* merge_lists(struct Node* head1, struct Node* head2)
{
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;

    struct Node* merged_head = NULL;
    struct Node* temp = NULL;

    if(head1->data <= head2->data)
    {
        merged_head = head1;
        head1 = head1->next;
    }
    else
    {
        merged_head = head2;
        head2 = head2->next;
    }

    temp = merged_head;

    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data <= head2->data)
        {
            temp->next = head1;
            head1 = head1->next;
        }
        else
        {
            temp->next = head2;
            head2 = head2->next;
        }
        temp = temp->next;
    }

    if(head1 != NULL)
    {
        temp->next = head1;
    }
    else
    {
        temp->next = head2;
    }

    return merged_head;
}

int main()
{
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    struct Node* temp = NULL;

    // First sorted list: 1 3 5 7
    int arr1[] = {1,3,5,7};
    for(int i = 0; i < 4; i++)
    {
        struct Node* new_node = create_node(arr1[i]);

        if(head1 == NULL)
        {
            head1 = new_node;
            temp = new_node;
        }
        else
        {
            temp->next = new_node;
            temp = new_node;
        }
    }

    // Second sorted list: 2 4 6 8
    int arr2[] = {2,4,6,8};
    temp = NULL;

    for(int i = 0; i < 4; i++)
    {
        struct Node* new_node = create_node(arr2[i]);

        if(head2 == NULL)
        {
            head2 = new_node;
            temp = new_node;
        }
        else
        {
            temp->next = new_node;
            temp = new_node;
        }
    }

    printf("First List:\n");
    display_list(head1);

    printf("Second List:\n");
    display_list(head2);

    struct Node* merged = merge_lists(head1, head2);

    printf("Merged List:\n");
    display_list(merged);

    return 0;
}