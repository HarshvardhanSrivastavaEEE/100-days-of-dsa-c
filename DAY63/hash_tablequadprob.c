#include <stdio.h>

#define SIZE 100

int hashTable[SIZE];

void init()
{
    for(int i = 0; i < SIZE; i++)
    {
        hashTable[i] = -1;
    }
}
void insert(int key)
{
    int index = key % SIZE;
    int i = 0;
    int newIndex;

    while(i < SIZE)
    {
        newIndex = (index + i * i) % SIZE;

        if(hashTable[newIndex] == -1)
        {
            hashTable[newIndex] = key;
            return;
        }

        i++;
    }

    printf("Hash table is full\n");
}
void display()
{
    for(int i = 0; i < SIZE; i++)
    {
        if(hashTable[i] != -1)
        {
            printf("%d : %d\n", i, hashTable[i]);
        }
    }
}

int main()
{
    init();

    for(int i = 0; i < 10; i++)
    {
        int value;
        printf("Enter the number: ");
        scanf("%d", &value);
        insert(value);
    }

    display();

    return 0;
}