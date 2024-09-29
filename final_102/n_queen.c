#include<stdio.h>
int backtacking(int map[5][5],int n,int current_row,int *num);
int is_valid(int map[5][5],int n,int current_row,int current_column);
int main()
{
    int n,map[5][5];
    int i,j;
    for(i = 0;i<5;i++)
    {
        for(j = 0;j<5;j++)
            map[i][j] = 0;
    }
    printf("Enter n : ");
    scanf("%d",&n);
    printf("\n");
    int num = 0;
    backtacking(map,n,0,&num);
    for(i = 0;i<5;i++)
    {
        for(j = 0;j<5;j++)
            printf("%d  ",map[i][j]);
        printf("\n");
    }
}
int backtacking(int map[5][5],int n,int current_row,int *num)
{
    int i;
    if(*num == n)
        return 1;
    if(current_row == n)
        return 0;
    for(i = 0;i<n;i++)
    {
        if(is_valid(map,n,current_row,i))
        {
            map[current_row][i] = 1;
            *num += 1;
            if(backtacking(map,n,i,num)) return 1;
            map[current_row][i] = 0;
            *num -= 1;
        }
    }
    return 0;
}
int is_valid(int map[5][5],int n,int current_row,int current_column)
{
    int i,j;
    for(i = 0;i<n;i++)
        if(map[current_row][i] == 1) return 0;
    for(i = 0;i<n;i++)
        if(map[i][current_column] == 1) return 0;
    if(map[current_row-1][current_column-1] == 1) return 0;
    if(map[current_row-1][current_column+1] == 1) return 0;
    if(map[current_row+1][current_column-1] == 1) return 0;
    if(map[current_row+1][current_column+1] == 1) return 0;
    return 1;
}