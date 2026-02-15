#include <stdio.h>

int main()
{
 int rows;
 int columns;
 printf("Enter the number of rows and columns \n");
 scanf("%d",&rows);
 scanf("%d",&columns);
 if( rows != columns)
 {
   return 0;
 }
 int matrix[rows][columns];
 printf("Lets input the elements of the matrix");
 for(int i = 0; i < rows; i++)
 {
  for(int j = 0; j < columns; j++)
  {
    scanf("%d",&matrix[i][j]);
  }
 }
 int sum = 0;
 for(int i = 0; i < rows; i++)
 {
  for(int j = 0; j < columns; j++)
  {
    if(i == j)
    {
      sum = sum + matrix[i][j];
    }
  }
 }
printf("Sum of diagonal elements of the entered matrix is: %d",sum);
}