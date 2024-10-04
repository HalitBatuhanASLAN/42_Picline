#include<stdio.h>
#include<locale.h>
void menu_choise();
int checking_news(char news_num);
void printing_news(char news_num, int choise);
void printing_readed();
int cube(int num);
int square(int num);
void finding_key_value(char news_num);
void printing_titles();
int empt_or_not();
int exist_news(char news_choise);
void menu();
int main()
{
    setlocale(LC_ALL, "Turkish");
    menu();
    return 0;
}
void menu_choise()
{
    printf("\nWhat do you want to do?\n");
    printf("a.Read a news\n");
    printf("b.List the readed news\n");
    printf("c.Get decrypted information from news\n");
    printf("Your choise is : ");
}
int checking_news(char news_num)
{
    FILE *readed;/*File pointer for read mode*/
    char num;/*storing readed character*/
    int controller = 1;/*control variable to check news is read or not*/
    readed = fopen("readed_news_id.txt","r");
    /*Reading characters with while loop*/
    while(fscanf(readed,"%c",&num) == 1)
    {
        /*if news is readed change controller as 0*/
        if(news_num == num)
            controller = 0;
    }
    fclose(readed);
    return(controller);
}
void printing_news(char news_num,int choise)
{
    char character;/*storing readed character*/
    FILE *news;
    FILE *readed;/*File pointer for append mode*/
    int news_controller;/*control variable to check news is read or not*/
    readed = fopen("readed_news_id.txt","a");
    /*to open relevant txt file according to news_num*/
    switch(news_num)
    {
        case '1':
            news = fopen("1.txt","r");
            break;
        case '2':
            news = fopen("2.txt","r");
            break;
        case '3':
            news = fopen("3.txt","r");
            break;
        case '4':
            news = fopen("4.txt","r");
            break;
    }
    /*printing news with while loop*/
    while(fscanf(news,"%c",&character) == 1)
        printf("%c",character);
    fclose(news);
    printf("\n");
    /*to check to append in readed_news or not*/
    if(choise == 1)
    {
        news_controller = checking_news(news_num);
        if(news_controller == 1 && news_num < '5' && news_num > '0')
            fprintf(readed,"%c\n",news_num);
    }
    fclose(readed);
}
void printing_readed()
{
    FILE *readed;/*File pointer for read mode*/
    int number_news;/*taking number of news*/
    readed = fopen("readed_news_id.txt","r");
    /*with while loop prints the number of news which was read*/
    while(fscanf(readed,"%d",&number_news) == 1)
        printf("%d. news readed\n",number_news);
    fclose(readed);
}
int cube(int num)
{
    int i = 1;
    int result = 1;
    for(;i<=3;i++)
        result *= num;
    return(result);
}
int square(int num)
{
    num *= num;
    return(num);
}
void finding_key_value(char news_num)
{
    FILE * news;/*File pointer for news file*/
    char character;/*storing readed character*/
    int number_magic_num = 0;/*counting how many numbers are inside file*/
    int magic_num,choise = 0;/*taking magic num*/
    float key = 0;/*to store calculating key value*/
    /*opening relevant txt file*/
    switch(news_num)
    {
        case '1':
            news = fopen("1.txt","r");
            break;
        case '2':
            news = fopen("2.txt","r");
            break;
        case '3':
            news = fopen("3.txt","r");
            break;
        case '4':
            news = fopen("4.txt","r");
            break;
    }
    /*with loop taking characters*/
    while(fscanf(news,"%c",&character) == 1)
    {
        if(character == '#')
        {
            fscanf(news,"%d",&magic_num);
            magic_num = cube(magic_num) - square(magic_num) + 2;
            magic_num = square(magic_num);
            key += magic_num;
            number_magic_num++;
        }
    }
    printing_news(news_num,choise);
    printf("%c. news key is %.2f\n",news_num,key);
    fclose(news);
}
void printing_titles()
{
    char title;
    FILE *first_news;/*File pointer for the first news file*/
    FILE *second_news;/*File pointer for the second news file*/
    FILE *third_news;/*File pointer for the third news file*/
    FILE *forth_news;/*File pointer for the fourth news file*/
    printf("********Daily Press***********\n\n");
    printf("Today's news are listed for you :\n\n");
    first_news = fopen("1.txt","r");
    printf("Title of 1. news: ");
    while(fscanf(first_news,"%c",&title) == 1 && title != '\n')
        printf("%c",title);
    fclose(first_news);
    second_news = fopen("2.txt","r");
    printf("\nTitle of 2. news: ");
    while(fscanf(second_news,"%c",&title) == 1 && title != '\n')
        printf("%c",title);
    fclose(second_news);
    third_news = fopen("3.txt","r");    
    printf("\nTitle of 3. news: ");
    while(fscanf(third_news,"%c",&title) == 1 && title != '\n')
        printf("%c",title);
    fclose(third_news);
    forth_news = fopen("4.txt","r");
    printf("\nTitle of 4. news: ");
    while(fscanf(forth_news,"%c",&title) == 1 && title != '\n')
        printf("%c",title);
    fclose(forth_news);
    printf("\n");
}
int empt_or_not()
{
    FILE *readed;/*File pointer for read mode*/
    char number_news;/*storing readed character*/
    int controller = 0;/*Controller for whether file is empty or not*/
    readed = fopen("readed_news_id.txt","r");
    if(fscanf(readed,"%c",&number_news) == 1)
        controller = 1;
    fclose(readed);
    return(controller);
}
int exist_news(char news_choise)
{
    FILE *all_news;/*File pointer for all news IDs*/
    all_news = fopen("all_news_id.txt","r");
    int controller = 0;/*Controller for whether news_choise is exist or not*/
    char news_number;/*storing readed character*/
    /*readining news ith while loop*/
    while(fscanf(all_news,"%c",&news_number) == 1)
    {
        if(news_number == news_choise)
            controller = 1;
    }
    fclose(all_news);
    return(controller);
}
void menu()
{
    char news_choise,choise = 'y';/*Variables for news choice and user input*/
    int controller = 1,news_control,readed_control;/*Controller variables*/
    int selection = 1;/*variable for printing_news function*/
    printing_titles();/*Print titles of news*/
    int exist_news_cont = 0;/*Controller for existence of news*/
    while(choise == 'y')
    {
        menu_choise();
        scanf(" %c",&choise);
        switch(choise)
        {
            case 'a':
                exist_news_cont = 0;
                /*Loop till accepted news choice is given*/
                while(exist_news_cont == 0)
                {
                    printf("Which news do you want to read : ");
                    scanf(" %c",&news_choise);
                    /*Check if news exists*/
                    if(exist_news(news_choise) == 1)
                        exist_news_cont = 1;
                    else
                        printf("!!It is not a number of news\n");
                }
                /*Check if news is already read*/
                news_control = checking_news(news_choise);
                if(news_control == 0)
                {
                    printf("This news is readed. Do you want to read again? Yes(1)/No(0): ");
                    scanf(" %c",&choise);
                    if(choise == '1')
                        news_control = 1;
                    else if(choise != '0')
                        printf("It is an unaccepted valur\n");
                }
                if(news_control == 0)
                {
                    printf("Would you like to reading different news item? Yes(y)/No(n): ");
                    scanf(" %c",&choise);
                    controller = 0;
                }
                if(news_control == 1)
                {
                    printing_news(news_choise,selection);
                    controller = 1;
                }
                break;
            case 'b':
                /*Check if any news has been read*/
                readed_control = empt_or_not();
                if(readed_control == 0)
                    printf("No news has been read yet!!\n");
                else
                    printing_readed();
                controller = 1;
                break;
            case 'c':
                /*Loop until valid news choice is made*/
                exist_news_cont = 0;
                while(exist_news_cont == 0)
                {
                    printf("Which news do you want to learn key : ");
                    scanf(" %c",&news_choise);
                    if(exist_news(news_choise) == 1)
                        exist_news_cont = 1;
                    else
                        printf("!!It is not a number of news\n");
                }
                /*Finding key*/
                finding_key_value(news_choise);
                controller = 1;
                break;
            case 'y':
                controller = 1;
                break;
            case 'n':
                controller = 0;
                break;
            default:
                printf("!!Enter a valid value\n");
                controller = 1;
                break;
        }
        if(controller == 1)
        {
            printf("Do you want to countinue? Yes(y)/No(n): ");
            scanf(" %c",&choise);
        }
    }
    printf("Goodbye\n");
}