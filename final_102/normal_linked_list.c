#include<stdio.h>
#include<stdlib.h>
typedef struct LIST
{
    int data;
    struct LIST *next;
}list;
list *create_list();
void print_list(list *root);
void add_head(list *root,int x);
list *add_last(list *root,int x);
void add_sortly(list *root,int x);
void deleting(list *root,int x);
void sorting(list *root);
void reverse(list **root);
int main()
{
    list *head = NULL;
    list *tmp = head;
    int i;
    head = add_last(head,-15);
    print_list(head);
    for(i = 10;i>=1;i--)
    {
        add_sortly(head,i*10);
        print_list(head);
    }
    deleting(head,-15);
    print_list(head);/*
    sorting(head);
    print_list(head);*/
    reverse(&head);
    print_list(head);
    while(tmp)
    {
        head = head->next;
        free(tmp);
        tmp = head;
    }
    return 0;
}
void reverse(list **root)
{
    list *current = *root;
    list *prev = NULL;
    list *next= NULL;
    while(current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *root = prev;
}
/*
list *create_list()
{
    list *head = (list *)malloc(sizeof(list));
    head->next = NULL;
    return(head);
}*/
void print_list(list *root)
{
    list *tmp = root;
        while(tmp != NULL)
    {
        printf("%d  ",tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}
void add_head(list *root,int x)
{
    if(root == NULL)
    {
        root = (list *)malloc(sizeof(list));
        root->data = x;
        root->next = NULL;
    }
    else
    {
        list *tmp = (list *)malloc(sizeof(list));
        tmp->data = x;
        tmp->next = root;
        *root = *tmp;
        /*free(tmp);/*bunu unutma sadece tmp nerede tanımlı ise orada free yaparsın else dışında olmuyoe*/
    }
}
list *add_last(list *root,int x)
{
    list *tmp = (list *)malloc(sizeof(list));
    tmp->data = x;
    tmp->next = NULL;        
    if(root == NULL)
    {
        free(root);
        return(tmp);
    }
    else
    {
        list *iter = root;
        while(iter->next)
            iter = iter->next;
        iter->next = tmp;
    }
    return(root);
}
void add_sortly(list *root,int x)
{
    if(root == NULL)
    {
        root = (list *)malloc(sizeof(list));
        root->data = x;
        root->next = NULL;
        printf("a\n");
    }
    else if(root->data > x)
    {
        list *tmp = (list *)malloc(sizeof(list));
        tmp->data = x;
        tmp->next = root;
        root = tmp;
        /*free(tmp);*/
    }
    else
    {
        list *tmp = (list *)malloc(sizeof(list));
        list *iter = root;
        list *prev = root;
        tmp->data = x;
        tmp->next = NULL;
        while(iter != NULL && iter->data < x)
        {
            prev = iter;
            iter = iter->next;
        }
        tmp->next = iter;
        prev->next = tmp;
        /*free(tmp);*/
    }
}
void deleting(list *root,int x)
{
    list *iter = root;
    list *tmp = root;
    if(iter == NULL)
        printf("empty list\n");
    else if(iter->data == x)
    {
        list *new = iter->next;
        free(iter);
        *root = *new;
    }
    else
    {
        iter = iter->next;
        while(iter)
        {
            if(iter->data == x)
            {
                tmp->next = iter->next;
                free(iter);
                return;
            }
            tmp = iter;
            iter = iter->next;
        }
        printf("Data is not in list\n");
    }
}
void sorting(list *root)
{
    if(!root)
    {
        printf("list is empty");
        return;
    }
    list *d1,*d2,*d3;
    int d4;
    d1 = root;
    while(d1)
    {
        d2 = root;
        while(d2->next)
        {
            d3 = d2->next;
            if(d2->data > d3->data)
            {
                d4 = d2->data;
                d2->data = d3->data;
                d3->data = d4;
            }
            d2 = d2->next;
        }
        d1 = d1->next;
    }
}