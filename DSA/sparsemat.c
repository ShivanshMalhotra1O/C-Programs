#include <stdio.h>
#include <stdlib.h>
int main()
{
    int row, col, i, j, a[10][10], zerocount = 0, nonzerocount = 0;
    
    printf("Enter row:");
    scanf("%d", &row);
    printf("Enter Column:");
    scanf("%d", &col);
    printf("Enter Element of Matrix:");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Elements are:\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (a[i][j] == 0)
                zerocount++;
            else
                nonzerocount++;
        }
    }
    if (zerocount > nonzerocount)
        printf("Matrix is a sparse matrix");
    else
        printf("Matrix is not sparse matrix");
}