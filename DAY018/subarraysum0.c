#include <stdio.h>


int main()
{
    int size;
    printf("Please enter your the number of elements you want in your array \n");
    scanf("%d",&size);

    printf("Now lets input the elements of your array \n");
    int arr[size];
    for(int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    int cnt = 0;

    for(int i = 0; i < size; i++)
    {
        int sum = 0;
        for(int j = i; j < size; j++)
        {
         sum = sum + arr[j];
        if(sum == 0)
        {
            cnt++;
        }
        }
    }
    printf("Total number of subarrays with sum 0 are: %d",cnt);
}