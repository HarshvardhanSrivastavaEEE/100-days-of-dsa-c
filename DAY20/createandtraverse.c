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
}

int main()
{
    struct Node* head = NULL;
    struct Node* temp = NULL;
    for(int i = 0; i < 11; i++)
    {
            if(head == NULL)
            {
                struct Node* new_node = create_node(i);
                head = new_node;
                temp = new_node;
            }
            else
            {
                struct Node* new_node = create_node(i);
                temp->next = new_node;
                temp = new_node;
            }
    }

    struct Node* tempp = head;
    while(tempp)
    {
        printf("%d->",tempp->data);
        tempp = tempp->next;
    }
    printf("NULL");
}
