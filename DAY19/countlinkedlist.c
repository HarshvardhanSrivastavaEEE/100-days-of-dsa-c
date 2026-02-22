#include <stdio.h>
#include <stdlib.h>

struct Node{
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
    printf("NULL->");
    while(temp)
    {
       printf("%d->",temp->data);
       temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int number;
    printf("Enter the number of nodes you want in your linked list! \n"); 
    scanf("%d",&number);
    struct Node* head = NULL;
    struct Node* temp = head;
    for(int i = 0; i < number ;i++)
    {
        int num;
        printf("Enter the value of node %d: \n",i+1);
        scanf("%d",&num);
        struct Node* new_node = create_node(num);
        if(head == NULL)
        {
            head = new_node;
            temp = new_node;
        }
        else
        {
            temp->next = new_node;
            temp = new_node;
        }
    }
    printf("Displaying your list! \n");
    display_list(head);
}