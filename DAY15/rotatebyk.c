#include <stdio.h>
void reverse(int *arr,int low, int high)
{
    while(low < high)
    {
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        low++;
        high--;
    }
}
int main()
{
 int size;
 printf("Enter the number of elements in your array\n");
 scanf("%d",&size);
 printf("Now lets input the elements of the array\n");
 int arr[size];
 for(int i = 0; i < size; i ++)
 {
    scanf("%d",&arr[i]);
 }
 printf("Entered array is: \n");
 for(int i = 0; i < size; i++)
 {
    printf("%d ",arr[i]);
 }
 printf("\n");
 int position = 0;
 printf("Enter by how much you want to rotate to the right \n");
 scanf("%d",&position);
 position = position % size;
 int low = 0; 
 int high = size - 1;
 reverse(arr,low,high);
 high = position-1;
 reverse(arr,low,high);
 high = size-1;
 reverse(arr,position,high);
 printf("Rotated array is: \n");
 for(int i = 0; i < size; i++)
 {
    printf("%d ",arr[i]);
 }

 
}