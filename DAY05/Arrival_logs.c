#include <stdio.h>

int main()
{
  int size1;
  scanf("%d",&size1);
  int size2;
  scanf("%d",&size2);

 int arr_1[size1];
 int arr_2[size2];
 printf("Enter elements of the first array \n");
 for(int i = 0; i < size1; i++)
 {
  scanf("%d",&arr_1[i]);
 }
 printf("Enter elements of the second array \n");  
 for(int i = 0; i < size2; i++)
 {
  scanf("%d",&arr_2[i]);
 } 

int resultant_array[size1 + size2];
int i = 0;
int j = 0;
int k = 0;
while(i < size1 && j < size2)
 {
   if(arr_1[i] < arr_2[j])
   { 
      resultant_array[k] = arr_1[i];
      k++;
      i++;
   }
   else if(arr_1[i] > arr_2[j])
   {
      resultant_array[k] = arr_2[j];
      k++;
      j++;
   }
   else
   {
      resultant_array[k] = arr_1[i];
      k++;
      resultant_array[k] = arr_2[j];
      k++;
      i++;
      j++;
   }
 }
while (i < size1)
    {
        resultant_array[k] = arr_1[i];
        k++;
        i++;
    }

    while (j < size2)
    {
        resultant_array[k] = arr_2[j];
        k++;
        j++;
    }
printf("Resultant array is: \n");
for(int i = 0; i < size1 + size2; i++)
{
  printf("%d ",resultant_array[i]);
}
}