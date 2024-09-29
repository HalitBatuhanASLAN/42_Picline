#include<stdio.h>
#include<stdlib.h>

typedef struct LIST
{
    int data;
    struct LIST *next;  
    struct LIST *prev;
}dou_list;
void print_list(dou_list *head);
dou_list *add(dou_list *head,int a);
void delete(dou_list *head,int a);
void sorting(dou_list *head);
void add_sortly(dou_list *head,int a);
int main()
{
    dou_list *head = NULL;
    int i;
    head = add(head,130);
    head = add(head,120);
    head = add(head,150);
    print_list(head);
    for(i = 9;i>0;i--)
    {
        head = add(head,i*10);
        print_list(head);
    }
    delete(head,90);
    print_list(head);
    sorting(head);
    print_list(head);
    dou_list *tmp = head;
    while(tmp)
    {
        head = tmp->next;
        free(tmp);
        tmp = head;
    }
    free(head);
    return 0;
}
void sorting(dou_list *head)
{
    dou_list *iter = head,*n1 = head,*n2,*n3;
    int tmp;
    while(n1)
    {
        n2 = n1->next;
        while(n2)
        {
            if(n1->data > n2->data)
            {
                tmp = n1->data;
                n1->data = n2->data;
                n2->data = tmp;
            }
            n2 = n2->next;
        }
        n1 = n1->next;
    }
}
void add_sortly(dou_list *head,int a)
{
    dou_list *iter = head;
    dou_list *tmp;
    tmp = (dou_list *)malloc(sizeof(dou_list));
    tmp->prev = NULL;
    tmp->data = a;
    tmp->next = NULL;
    if(iter->data > a)
    {
        tmp->next = iter;
        iter->prev = tmp;
        head = tmp;
        free(tmp);
    }
    else
    {
        dou_list *prev = head;
        tmp->data = a;
        tmp->next = NULL;
        while(iter != NULL && iter->data < a)
        {
            prev = iter;
            iter = iter->next;
        }
        tmp->next = iter;
        if (prev != NULL) {
            prev->next = tmp;
            tmp->prev = prev;
        }
        if (iter != NULL) {
            iter->prev = tmp;
        }
        /*free(tmp);*/
    }
}
void delete(dou_list *head,int a)
{
    dou_list *iter = head;
    dou_list *tmp = head;
    if(head == NULL)
        printf("list is empty\n");
    else if(head->data == a)
    {
        dou_list *new = iter->next;
        new->prev = NULL;
        free(iter);
        *head = *new;
    }
    else
    {
        tmp = iter;
        while(iter)
        {
            if(iter->data == a)
            {
                tmp->next = iter->next;
                iter->next->prev = tmp;
                free(iter);
                return;
            }
            tmp = iter;
            iter = iter->next;
        }
    }
}
dou_list *add(dou_list *head,int a)
{
    if(head == NULL)
    {
        head = (dou_list *)malloc(sizeof(dou_list));
        head->prev = NULL;
        head->next = NULL;
        head->data = a;
    }
    else
    {
        dou_list *iter = head;
        while(iter->next) iter = iter->next;
        dou_list *tmp = (dou_list *)malloc(sizeof(dou_list));
        tmp->data = a;
        iter->next = tmp;
        tmp->next = NULL;
        tmp->prev = iter;
    }
    return(head);
}
void print_list(dou_list *head)
{
    if(head == NULL) printf("list is empty\n");
    else if(head->next == NULL) printf("%d  ",head->data);
    else
    {
        dou_list *iter = head;
        while(iter)
        {
            printf("%d  ",iter->data);
            iter = iter->next;
        }
    }
    printf("\n");
}