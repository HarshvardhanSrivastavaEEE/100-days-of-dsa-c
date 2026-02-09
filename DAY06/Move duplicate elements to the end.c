#include <stdio.h>


int main()
{
    int size;
    printf("Enter the size of your array.\n");
    scanf("%d",&size);
    printf("Enter the elements of your array in sorted matter \n");
    int arr[size];
    for(int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    int j = 0;
    for(int i = 1; i < size; i++)
    {
        if(arr[i] == arr[j])
        {
            continue;
        }
        else
        {
            j++;
            arr[j] = arr[i];
        }
    }
    printf("Printing the array\n");
    for(int i = 0; i <= j; i++)
    {
        printf("%d ",arr[i]);
    }
}