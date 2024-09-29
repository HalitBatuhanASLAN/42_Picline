#include<stdio.h>
#include<stdlib.h>

int main()
{
    int **arr;
    arr = (int **)malloc(sizeof(int *)*5);
    int i,j,k =1;
    for(i = 0;i<5;i++)
    {
        arr[i] = (int *)malloc(sizeof(int)*3);
        for(j = 0;j<3;j++,k++)
        {
            arr[i][j] = k;
            printf("%d  ",arr[i][j]);
        }
        printf("\n");
    }
    k = 0;
    for(i = 0;i<5;i++)
    {
        arr[i] = realloc(arr[i],sizeof(int)*4);
        for(j = 0;j<4;j++,k++)
        {
            arr[i][j] = k;
            printf("%d  ",arr[i][j]);
        }
        printf("\n");
    }
    for(i = 0;i<5;i++)
        free(arr[i]);
    free(arr);
}