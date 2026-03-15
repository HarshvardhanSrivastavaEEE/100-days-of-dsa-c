#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* top = NULL;

struct Node* push(int value)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if(new_node == NULL)
    {
        printf("Stack overflow malloc failed! \n");
        return NULL;
    }
    new_node->data = value;
    new_node->next = top;
    top = new_node;
    return new_node;
}

void pop()
{
    if(top == NULL)
    {
        printf("Stack undeflow! \n");
        printf("Stack is empty!! \n");
        return;
    }
    struct Node* temp = top;
    top = top->next;
    free(temp);
}

struct Node* pop_specific(int position, struct Node* top)
{
    if(top == NULL || position <= 0) return top;

    if(position == 1) 
    {
        struct Node* del = top;
        top = top->next;
        free(del);
        return top;
    }

    struct Node* temp = top;
    int cnt = 1;

    while(temp != NULL && cnt + 1 != position)
    {
        temp = temp->next;
        cnt++;
    }

    if(temp == NULL || temp->next == NULL) return top; 

    struct Node* to_be_del = temp->next;
    temp->next = to_be_del->next;
    free(to_be_del);

    return top;
}

void display(struct Node* top)
{
   struct Node* temp = top;
   while(temp)
   {
    printf("%d \n",temp->data);
    printf("|\n");
    printf("V\n");
    temp = temp->next;
   }
   printf("NULL\n");
}
int main()
{
 for(int i = 0; i < 11; i++)
 {    
    push(i);
 }
 display(top);
 pop();
 display(top);
 top = pop_specific(4,top);
 display(top);
}