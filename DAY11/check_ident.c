#include <stdio.h>

int main()
{
    int rows;
    int columns;

    printf("Enter the number of rows and columns\n");
    scanf("%d", &rows);
    scanf("%d", &columns);

    if(rows != columns)
    {
        printf("Not identity matrix\n");
        return 0;
    }

    int matrix[rows][columns];

    printf("Lets input the elements of the matrix\n");

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            if(i == j)
            {
                if(matrix[i][j] != 1)
                {
                    printf("Not identity matrix\n");
                    return 0;
                }
            }
            else
            {
                if(matrix[i][j] != 0)
                {
                    printf("Not identity matrix\n");
                    return 0;
                }
            }
        }
    }

    printf("Matrix entered is identity matrix\n");
    return 0;
}
