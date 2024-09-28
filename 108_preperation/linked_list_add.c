#include<stdio.h>
#include<stdlib.h>
struct list
{
    int number;
    struct list *next;
};

struct list *adding(struct list *adding_list,int adding_number)
{
    struct list *tmp = (struct list *)malloc(sizeof(struct list));
    if(adding_list == NULL)
    {
        tmp->number = adding_number;
        tmp->next = NULL;
        adding_list = tmp;
    }
    else
    {
        struct list *current = adding_list;
        tmp->number = adding_number;
        tmp->next = NULL;
        while(current->next != NULL)
            current = current->next;
        current->next = tmp;
    }
    return(adding_list);
}

struct list *adding_first(struct list *adding_list,int adding_number)
{
    struct list *tmp = (struct list *)malloc(sizeof(struct list));
    struct list *current = adding_list;
    tmp->number = adding_number;
    tmp->next = current;
    return(tmp);
}

struct list *deleting_num(struct list *adding_list,int deleting_number)
{
    struct list *tmp = (struct list *)malloc(sizeof(struct list));
    struct list *current = adding_list;
    while(current->number != deleting_number)
    {
        tmp = current;
        current = current->next;
    }
    tmp->next = current->next;
    free(current);
    return(adding_list);
}

void printing_list(struct list *printing_list)
{
    struct list *tmp = printing_list;
    while(tmp->next != NULL)
    {
        printf("%d,",tmp->number);
        tmp = tmp->next;
    }
    printf("%d",tmp->number);
    printf("\n");
}
int main()
{
    struct list *main_list = NULL;
    int i = 6,number;
    for(;i>0;i--)
    {
        printf("enter num : ");
        scanf("%d",&number);
        main_list = adding(main_list,number);
        printing_list(main_list);
    }
    int toppest_num = 100;
    main_list = adding_first(main_list,toppest_num);
    printing_list(main_list);
    int deleting_number = 15;
    main_list = deleting_num(main_list,deleting_number);
    printing_list(main_list);
    
}