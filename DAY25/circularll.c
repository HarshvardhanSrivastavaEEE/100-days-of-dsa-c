#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};


struct Node* create_node(int value)
{
 struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
 new_node->data = value;
 new_node->next = NULL;
 new_node->prev = NULL;
 return new_node;
}
void display_list(struct Node* head)
{
    struct Node* temp = head;
    printf("NULL");
    while(temp)
    {
        printf("<-->%d",temp->data);
        temp = temp->next;
    }
    printf("<-->NULL\n");
}

int main()
{
    int n;
    printf("Hello user please enter the number of nodes \n");
    scanf("%d",&n);
    struct Node* head = NULL;
    struct Node* temp = NULL;


    for(int i = 0; i < n; i++)
    {
        if(head == NULL)
        {
            struct Node* new_node = create_node(i);
            head = new_node;
            temp = new_node;
            new_node->prev = NULL;
        }
        else
        {
            struct Node* new_node = create_node(i);
            new_node->prev = temp;
            temp->next = new_node;
            temp = new_node;
        }
    }
    display_list(head);
}