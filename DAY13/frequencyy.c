#include <stdio.h>
#include <limits.h>
int main()
{
    int size;
    printf("Enter the size of your array \n");
    scanf("%d",&size);
    int arr[size];
    printf("Now lets input the elements of your array");

    for(int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    int max = INT_MIN;
    for(int i = 0; i < size ; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    int dummy[max + 1];

 
    for(int i = 0; i <= max; i++)
    {
    dummy[i] = 0;
    }
    for(int i = 0; i < size; i++)
    {
        dummy[arr[i]]++;
    }
    for(int i = 0; i < max+1; i++)
    {
        if(dummy[i] >= 1)
        {
            printf("%d:%d \n",i,dummy[i]);
        }
    }

}