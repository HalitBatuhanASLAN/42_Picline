#include<stdio.h>
#include<stdlib.h>
/*burada ilk elemanı silerken hata alıyorum segmentation fault bir ara buna bakmak lazım*/
typedef struct Circular
{
    int data;
    struct Circular *next;
}circular;
void print_circular(circular *head);
circular *add(circular *head,int data);
void add_sortly(circular *head,int data);
void delete(circular *head,int data);
void sorting(circular *head);
int main()
{
    circular *head = NULL;
    head = add(head,1907);
    int i=10;
    for(;i>0;i--)
    {
        add_sortly(head,i+15);
        print_circular(head);
    }
    sorting(head);
    print_circular(head);
    delete(head,16);
    print_circular(head);
    circular *tmp = head->next;
    circular *next;
    while(tmp != head)
    {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    free(head);
}
void delete(circular *head,int data)
{
    circular *iter = head;
    if(iter->data == data)
    {
        circular *tmp = head;
        while(tmp->next != head)
            tmp = tmp->next;
        tmp->next = iter->next;
        *head = *tmp;
        free(iter);
    }
    else
    {
        /*circular *iter = head;*/
        circular *prev;
        do
        {
            prev = iter;
            iter = iter->next;
            if(iter->data == data)
            {
                circular *new = iter;
                prev->next = new->next;
                free(new);
                return;
            }
        }while(iter->next != head);
    }
}
void sorting(circular *head)
{
    int tmp;
    circular *n1,*n2,*n3;
    n1 = head;
    do
    {
        n2 = head;
        do
        {
            n3 = n2->next;
            if(n2->data > n3->data)
            {
                tmp = n2->data;
                n2->data = n3->data;
                n3->data = tmp;
            }
            n2 = n2->next;
        }while(n2->next != head);
        n1 = n1->next;
    }while(n1->next != head);
}
void add_sortly(circular *head,int data)
{
    if(data < head->data)
    {
        circular *iter = head;
        do
        {
            iter = iter->next;
        }while(iter->next != head);
        circular *new = (circular *)malloc(sizeof(circular));
        new->data = data;
        new->next = head;
        iter->next = new;
    }
    else
    {
        circular *iter = head;
        circular *prev;
        do
        {
            prev = iter;
            iter = iter->next;
            if(iter->data > data)
            {
                circular *new = (circular *)malloc(sizeof(circular));
                new->data = data;
                new->next = iter;
                prev->next = new;
                return;
            }
        }while(iter->next != head);
        
        circular *new = (circular *)malloc(sizeof(circular));
        new->data = data;
        new->next = iter->next;
        prev->next->next = new;
        return;
    }
}
circular *add(circular *head,int data)
{
    if(head == NULL)
    {
        circular *new = (circular *)malloc(sizeof(circular));
        new->data = data;
        new->next = new;
        return(new);
    }
    else
    {
        circular *iter = head;
        do
        {
            iter = iter->next;
        }while(iter->next != head);
        circular *new = (circular *)malloc(sizeof(circular));
        iter->next = new;
        new->data = data;
        new->next = head;
        return(head);
    }
}
void print_circular(circular *head)
{
    if(head == NULL)
        printf("Empty list\n");
    else
    {
        circular *iter = head;
        do
        {
            printf("%d  ",iter->data);
            iter = iter->next;
        }while(iter != head);    
    }
    printf("\n");
}