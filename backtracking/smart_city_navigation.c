#include<stdio.h>
#define STREET_CENTER 1 /*to keep street number of dispatch center*/
#define AVENUE_CENTER 1 /*to keep avenue number of dispatch center*/
int num_paths_home(int street ,int avenue);
int main()
{
    int street,avenue,flag = 1,paths_num = 0;
    /*if user does not enter accepted values for street and avenue takes new ones*/
    do
    {
        printf("Enter the street number : ");
        scanf("%d",&street);
        printf("Street : %d\n",street);
        printf("Enter the avenue number : ");
        scanf("%d",&avenue);
        printf("Avenue : %d\n",avenue);
        /*conditions if street and avenue values are acceptable or not*/
        if(street<STREET_CENTER)
            printf("Street must be greater or equal than %d\n",STREET_CENTER);
        if(avenue<AVENUE_CENTER)
            printf("Avenue must be greater or equal than %d\n",AVENUE_CENTER);
        if(avenue == AVENUE_CENTER && street == STREET_CENTER)
            printf("It is the position of dispatch center\n");
        if((street == STREET_CENTER && avenue>AVENUE_CENTER) || (street>STREET_CENTER && avenue == AVENUE_CENTER))
            flag = 0;
        if(avenue > AVENUE_CENTER && street > STREET_CENTER)
            flag = 0;
    }while(flag == 1);
    paths_num = num_paths_home(street,avenue);
    printf("Number or optimal paths to take back home : %d\n",paths_num);
}
/*function calculates number of paths by recursion mentality*/
int num_paths_home(int street ,int avenue)
{
    int paths_num = 1;/*path number beginnig*/
    /*if current street and avenue is not same with center ones then recall same function again*/
    if(street != STREET_CENTER && avenue != AVENUE_CENTER) 
        paths_num = num_paths_home(street-1,avenue) + num_paths_home(street,avenue-1);
    return(paths_num);
}