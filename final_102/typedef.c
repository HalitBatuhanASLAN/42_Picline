#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct xxx{char name[20];int age;}yyy;
struct araba
{
    int engine,year;
};
struct oto
{
    int engine,year;
}xyz;
typedef struct
{
    int engine,year;
}bus;
typedef struct tren
{
    int engine,year;
}gem;
void taking_parameter(yyy *exa);
void taking_parameter_strcpy(yyy *exa);
int main()
{
    struct araba ford;
    struct oto merso;
    bus volvo;
    gem abc;
/*    yyy ex1;
    strcpy(ex1.name,"araba ");
    yyy *ex2 = (yyy *)malloc(sizeof(yyy));
    strcpy(ex2->name,"is good");
    printf("%s%s\n\n",ex1.name,ex2->name);


    yyy *ex3 = (yyy *)malloc(sizeof(yyy));
    taking_parameter(ex3);
    printf("%s and %d\n",ex3->name,ex3->age);
    yyy ex4;
    taking_parameter(&ex4);
    printf("%s and %d\n\n",ex4.name,ex4.age);


    taking_parameter_strcpy(&ex1);
    printf("%s and %d\n",ex1.name,ex1.age);
    taking_parameter_strcpy(ex2);
    printf("%s and %d\n\n",ex2->name,ex2->age);
    
    free(ex3);*/



}

void taking_parameter_strcpy(yyy *exa)
{
    char *tmp = (char *)malloc(sizeof(char)*15);
    int age;
    printf("Wnter name : ");
    scanf("%s",tmp);
    strcpy(exa->name,tmp);/*unutma*/
    printf("Enter age : ");
    scanf("%d",&age);/*unutma*/
    exa->age = age;
    free(tmp);
}

void taking_parameter(yyy *exa)
{
    printf("Wnter name : ");
    scanf("%s",exa->name);/*unutma*/
    printf("Enter age : ");
    scanf("%d",&(exa->age));/*unutma*/
}