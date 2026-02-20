#include <stdio.h>

int main()
{
  int rows;
  int columns;
  printf("Enter number of rows you want in your matrix please! \n");
  scanf("%d",&rows);
  printf("Enter number of columns you want in your matrix please! \n");
  scanf("%d",&columns);

  int arr[rows][columns];
  if(rows != columns)
  {
    printf("Matrix is not symmetric!\n");
    return 0;
  }
  printf("Now lets input the elements of a matrix!\n");
  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < columns; j++)
    {
        printf("Enter element of %dth row and %dth column: ",i+1,j+1);
        scanf("%d",&arr[i][j]);
    }
    printf("\n");
  }

  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < columns; j++)
    {
        if(arr[i][j] != arr[j][i])
        {
            printf("Matrix is not symetric! \n");
            return 0;
        }
    }
  }
  printf("Matrix is symetri! \n");
}