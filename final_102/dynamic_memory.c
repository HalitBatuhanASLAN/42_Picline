/*burada klasik array mantığı ile de matris[i][j] de yapılabilir*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void print_matris(int **matris,int row,int column);
void creating_matris(int ***matris,int row,int column);
int main()
{
    int **matris,row,column;
    printf("Enter row : ");
    scanf("%d",&row);
    printf("Enter column : ");
    scanf("%d",&column);
    creating_matris(&matris,row,column);
    printf("\n\n");
    print_matris(matris,row,column);
    int i;
    for(i = 0;i<row;i++)
        free(matris[i]);
    free(matris);
}
void creating_matris(int ***matris,int row,int column)
{
    int i,j;
    *(matris) = (int **)malloc(sizeof(int *)*row);
    for(i = 0;i<row;i++)
    {
        *(*matris + i) = (int *)malloc(sizeof(int)*column);
        for(j = 0;j<column;j++)
        {
            *(*(*matris + i)+ j) = i*j;
            printf("%d  ",*(*(*matris + i)+j));
        }
        printf("\n");
    }
}

void print_matris(int **matris,int row,int column)
{
    int i,j;
    printf("\n");
    for(i = 0;i<row;i++)
    {
        for(j = 0;j<column;j++)
            printf("%d  ",*(*(matris + i) + j));
        printf("\n");
    }
}
/*iki boyutlu malloc kullanımı
int main()
{
    int i,j,row,column;
    printf("Enter row number : ");
    scanf("%d",&row);
    printf("Enter column number : ");
    scanf("%d",&column);
    int **ptr;
    ptr = (int **)malloc(sizeof(int *)*row);
    for(i = 0;i<row;i++)
    {
        *(ptr + i) = (int *)malloc(sizeof(int)*column);
        for(j = 0;j<column;j++)
        {
            *(*(ptr + i)+j) = i*j;
            printf("%d  ",*(*(ptr + i) + j));
        }
        printf("\n");
    }
    print_matris(ptr,row,column);
    free(ptr);
}*/

/*bir boyutlu malloc kullanımı
int main()
{
    int *a,number,i;
    printf("how many numners : ");
    scanf("%d",&number);
    a = (int *)malloc(sizeof(int)*number);
    for(i = 0;i<number;i++)
    {
        *(a+i) = i*10;
        printf("%d  ",*(a+i));
    }
    free(a);
}*/