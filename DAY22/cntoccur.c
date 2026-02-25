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
    int n;
    printf("Enter the number of nodes you want! \n");
    scanf("%d",&n);
    int data;
    struct Node* head = NULL;
    struct Node* temp = NULL;
    for(int i = 0; i < n; i++)
    {
        if(head == NULL)
        {
        printf("Enter the data field of the Node #%d\n",i+1);
        scanf("%d",&data);
        struct Node* new_node = create_node(data);
        head = new_node;
        temp = new_node;
        }
        printf("Enter the data field of the Node #%d\n",i+1);
        scanf("%d",&data);
        struct Node* new_node = create_node(data);
        temp->next = new_node;
        temp = new_node;
    }

    struct Node* tem = head;
    while(tem)
    {
        printf("%d->",tem->data);
        tem = tem->next;
    }
    printf("NULL\n");
    int var;
    printf("Enter the variable to count the occurances of! \n");
    scanf("%d",&var);
    struct Node* tm = head;
    int cnt = 0;
    while(tm)
    {
        if(tm->data == var)
        {
            cnt++;
        }
        tm = tm->next;
    }
    printf("%d occured %d times!",var,cnt);

}