#include<stdio.h>
/*defining some special numbers for special characers in map*/
#define TREE 1 /*to special number for trees in map to keep in integer array */
#define SPACE 2 /*to special number for spaces in map to keep in integer array */
#define RARE_FLOWER 3 /*to special number for flowers in map to keep in integer array */
#define BOTANIST 4 /*to special number for botanist in map to keep in integer array */
#define MAX 100 /*max size to give size beginnig of the program for arrays*/
/*struct type to keep forest informations*/
typedef struct
{
    int map[MAX][MAX];/*map array as integer*/
    int width; /*to keep width of map(y-axis column value)*/
    int height; /*to keep height of map(x-axis row value)*/
    int flower_x[MAX]; /*to keep x cordinates of flowers*/
    int flower_y[MAX]; /*to keep y cordinates of flowers*/
}Forest;
/*struct type to keep botanist informations*/
typedef struct
{
    int coord_x[MAX]; /*x cordinates of botanist on each position of botanist*/
    int coord_y[MAX]; /*y cordinates of botanist on each position of botanist*/
    int number_of_bottles; /*to keep total number of bottles that botanist has*/
}Botanist;
/*prototypes of functions*/
void init_game(Forest *forest, Botanist *botanist);
void display_forest(Forest *forest,Botanist *botanist,int *number_of_move,int *number_of_collected_flowers,char direction);
void search(Forest *forest,Botanist *botanist,int *number_of_move,int total_flowers,int *number_of_collected_flowers);
void last_version(Forest *forest);
int main()
{
    Forest forest;
    Botanist botanist;
    int number_of_move = 0;/*keeping movement number as index number for botanist cordinates array*/
    /*to keep flowers numbers both total and collected ones*/
    int total_flowers = 0,number_of_collected_flowers = 0;
    /*for initializing informations of botanist and forest structs*/
    init_game(&forest,&botanist);
    int i,j;
    /*to count total number of rare flowers*/
    for(i = 0;i<forest.height;i++)
    {
        for(j = 0;j<forest.width;j++)
            if(forest.map[i][j] == RARE_FLOWER) total_flowers++;
    }
    /*to change direction of botanist and situatipn of map*/
    search(&forest,&botanist,&number_of_move,total_flowers,&number_of_collected_flowers);
    /*printing last situation of map into another file*/
    last_version(&forest);
    printf("\n");
}
/*writing last situtation of forest into another txt file*/
void last_version(Forest *forest)
{
    FILE *last;
    /*open file to write*/
    last = fopen("last.txt","w");
    int i,j;
    char character;
    /*from first line-colum value to last ones take character from array*/
    for(i = 0;i<forest->height;i++)
    {
        for(j = 0;j<forest->width;j++)
        {
            /*for all numbers in array it assign relevent character to character variable*/
            if(forest->map[i][j] == TREE) character = 'T';
            else if(forest->map[i][j] == BOTANIST) character = 'B';
            else if(forest->map[i][j] == RARE_FLOWER) character = 'X';
            else if(forest->map[i][j] == SPACE) character = ' ';
            /*except last column write comma too with character*/
            /*for last column situation write just character*/
            if(j != (forest->width -1)) fprintf(last,"%c,",character);
            else fprintf(last,"%c",character);
        }
        /*if it is not last line add skip to new line*/
        if(i != (forest->height -1)) fprintf(last,"\n");/*to skip new line*/
    }
    /*close file*/
    fclose(last);
}
/*do changes according to direction of user*/
void display_forest(Forest *forest,Botanist *botanist,int *number_of_move,int *number_of_collected_flowers,char direction)
{
    /*according to direction value do changes on map and botanist cordinates*/
    switch(direction)
    {
        /*increment number of movement then*/
        /*changes botanist cordinates index according to movement and according to new cordinates*/
        /*update botanist position on the map*/
    case 'L':
    case 'l':
        /*for moving botanist to left changes current position with space*/
        forest->map[botanist->coord_x[(*number_of_move)]][botanist->coord_y[(*number_of_move)]] = SPACE;
        (*number_of_move)++;
        botanist->coord_x[*number_of_move] = botanist->coord_x[(*number_of_move)-1];
        botanist->coord_y[*number_of_move] = botanist->coord_y[(*number_of_move)-1] -1;
        forest->map[botanist->coord_x[*number_of_move]][botanist->coord_y[*number_of_move]] = BOTANIST;
        break;
    case 'r':
    case 'R':
        /*for moving botanist to right changes current position with space*/
        forest->map[botanist->coord_x[(*number_of_move)]][botanist->coord_y[(*number_of_move)]] = SPACE;
        (*number_of_move)++;
        botanist->coord_x[*number_of_move] = botanist->coord_x[(*number_of_move)-1];
        botanist->coord_y[*number_of_move] = botanist->coord_y[(*number_of_move)-1] + 1;
        forest->map[botanist->coord_x[*number_of_move]][botanist->coord_y[*number_of_move]] = BOTANIST;
        break;
    case 'U':
    case 'u':
        /*for moving botanist to upward changes current position with space*/
        forest->map[botanist->coord_x[(*number_of_move)]][botanist->coord_y[(*number_of_move)]] = SPACE;
        (*number_of_move)++;
        botanist->coord_x[*number_of_move] = botanist->coord_x[(*number_of_move)-1]-1;
        botanist->coord_y[*number_of_move] = botanist->coord_y[(*number_of_move)-1];
        forest->map[botanist->coord_x[*number_of_move]][botanist->coord_y[*number_of_move]] = BOTANIST;
        break;
    case 'D':
    case'd':
        /*for moving botanist to downward changes current position with space*/
        forest->map[botanist->coord_x[(*number_of_move)]][botanist->coord_y[(*number_of_move)]] = SPACE;
        (*number_of_move)++;
        botanist->coord_x[*number_of_move] = botanist->coord_x[(*number_of_move)-1]+1;
        botanist->coord_y[*number_of_move] = botanist->coord_y[(*number_of_move)-1];
        forest->map[botanist->coord_x[*number_of_move]][botanist->coord_y[*number_of_move]] = BOTANIST;
        break;
    }
    int i = 0,j=0;
    char character;
    printf("\n");
    /*from first line-colum value to last ones take character from array*/
    for(;i<forest->height;i++)
    {
        for(j=0;j<forest->width;j++)
        {
            /*for all numbers in array it assign relevent character to character variable*/
            if(forest->map[i][j] == TREE) character = 'T';
            else if(forest->map[i][j] == SPACE) character = ' ';
            else if(forest->map[i][j] == BOTANIST) character = 'B';
            else if(forest->map[i][j] == RARE_FLOWER) character = 'X';
            /*except last column write comma too with character*/
            /*for last column situation write just character*/
            if(j != forest->width -1) printf("%c,",character);
            else printf("%c",character);
        }
        printf("\n");/*to skip new line*/
    }
    /*writing number of not used bottle,collected flower number and current index of botanist on map*/
    printf("\nThe number of not used bottle is : %d\n",botanist->number_of_bottles);
    printf("The number of collected flowers is : %d\n",*number_of_collected_flowers);
    printf("Current cordinates of botanist is(%d,%d)\n",botanist->coord_x[*number_of_move],botanist->coord_y[*number_of_move]);
}
/*takes choise of user and makes changes*/
void search(Forest *forest,Botanist *botanist,int *number_of_move,int total_flowers,int *number_of_collected_flowers)
{
    char direction,character;
    int flag = 0,i,j;
    printf("\n");
    /*if user wants to exit assign 2 to flag*/
    /*if user entered direction makes chanages on map assigns 1 to flag*/
    do
    {
        /*enter direction from user*/
        printf(" /\\/\\/\\/\\/\\/\\/\\/\\/\\\n");
        printf("<  (R,r) for right >\n");
        printf("<  (L,l) for left  >\n");
        printf("<  (U,u) for up    >\n");
        printf("<  (D,d) for down  >\n");
        printf(" ++++++++++++++++++\n");
        printf("Enter direstion for botanist : ");
        scanf(" %c",&direction);
        switch(direction)
        {
            /*for left direction*/
            case 'l':
            case 'L':
                /*if botanist is on leftest of map write error message and countinue loop again*/
                if(botanist->coord_y[*number_of_move] == 0)
                {
                    printf("!!!You are on the left-end side of the map.You can not go left anymore\n\n");
                    continue;
                }
                /*if there is a tree on left write error message and countinue loop again*/
                else if(forest->map[botanist->coord_x[(*number_of_move)]][botanist->coord_y[(*number_of_move)]-1] == TREE)
                {
                    printf("!!!Chose another direction there is a tree on that direction\n\n");
                    continue;
                }
                /*if botanist finds flower write message and increment number of flower and decrement number of bottles*/
                else if(forest->map[botanist->coord_x[(*number_of_move)]][botanist->coord_y[(*number_of_move)]-1] == RARE_FLOWER)
                {
                    printf("I've found it\n");
                    (*number_of_collected_flowers)++;
                    botanist->number_of_bottles--;
                }
                flag = 1;
                break;
            /*for right direction*/
            case 'r':
            case 'R':
                /*if botanist is on rightest of map write error message and countinue loop again*/
                if(botanist->coord_y[*number_of_move] == (forest->width -1))
                {
                    printf("!!!You are on the right-end side of the map.You can not go right anymore\n\n");
                    continue;
                }
                /*if there is a tree on right write error message and countinue loop again*/
                else if(forest->map[botanist->coord_x[(*number_of_move)]][botanist->coord_y[(*number_of_move)]+1] == TREE)
                {
                    printf("!!!Chose another direction there is a tree on that direction\n\n");
                    continue;
                }
                /*if botanist finds flower write message and increment number of flower and decremen number of bottles*/
                else if(forest->map[botanist->coord_x[(*number_of_move)]][botanist->coord_y[(*number_of_move)]+1] == RARE_FLOWER)
                {
                    printf("I've found it\n");
                    (*number_of_collected_flowers)++;
                    botanist->number_of_bottles--;
                }
                flag = 1;
                break;
            /*for upward*/
            case 'u':
            case 'U':
                /*if botanist is on top of map write error message and countinue loop again*/
                if(botanist->coord_x[*number_of_move] == 0)
                {
                    printf("!!!You are on the top side of the map.You can not go upward anymore\n\n");
                    continue;
                }
                /*if there is a tree on upward write error message and countinue loop again*/
                else if(forest->map[botanist->coord_x[(*number_of_move)]-1][botanist->coord_y[(*number_of_move)]] == TREE)
                {
                    printf("!!!Chose another direction there is a tree on that direction\n\n");
                    continue;
                }
                /*if botanist finds flower write message and increment number of flower and decremen number of bottles*/
                else if(forest->map[botanist->coord_x[(*number_of_move)]-1][botanist->coord_y[(*number_of_move)]] == RARE_FLOWER)
                {
                    printf("I've found it\n");
                    (*number_of_collected_flowers)++;
                    botanist->number_of_bottles--;
                }
                flag = 1;
                break;
            /*for downward*/
            case 'd':
            case 'D':
                /*if botanist is on bottom of map write error message and countinue loop again*/
                if(botanist->coord_x[*number_of_move] == (forest->height -1 ))
                {
                    printf("!!!You are on the bottom side of the map.You can not go downwardl a anymore\n\n");
                    continue;
                }
                /*if there is a tree on downward write error message and countinue loop again*/
                else if(forest->map[botanist->coord_x[(*number_of_move)]+1][botanist->coord_y[(*number_of_move)]] == TREE)
                {
                    printf("!!!Chose another direction there is a tree on that direction\n\n");
                    continue;
                }
                /*if botanist finds flower write message and increment number of flower and decremen number of bottles*/
                else if(forest->map[botanist->coord_x[(*number_of_move)]+1][botanist->coord_y[(*number_of_move)]] == RARE_FLOWER)
                {
                    printf("I've found it\n");
                    (*number_of_collected_flowers)++;
                    botanist->number_of_bottles--;
                }
                flag = 1;
                break;
            /*to exit*/
            case 'E':
            case 'e':
                flag = 2;
                break;
            /*for default values*/
            default:
                printf("!!!Please enter a valid direction\n\n");
                break;
        }
    }
    while(flag == 0);/*if user entered values is not excepted or on that direction there is a tree or*/
    /*botanist can not go that direction any more it takes another direction from user*/
    /*if user entered an accepted value it makes changes in display forest function*/
    /*and if game is not over it recalls search function again and countinue to take direction form user*/
    if(flag == 1)
    {
        display_forest(forest,botanist,number_of_move,number_of_collected_flowers,direction);
        /*if still there is flower or bottle recall search function again as recursive*/
        if(*number_of_collected_flowers != total_flowers && botanist->number_of_bottles != 0)
            search(forest,botanist,number_of_move,total_flowers,number_of_collected_flowers);
        /*if bottle number is finished it prints error message and finishes program*/
        else if(*number_of_collected_flowers != total_flowers && botanist->number_of_bottles == 0)
            printf("Unfortunatelly your bottle has been ended.You can not countinue the game\n");
        /*for other situation it has only one meaning  that is all flowers are finished and finishes program*/
        else
            printf("You have found all flowers.Congratulations\n");
    }
    /*if user wants to exit game it prints exit message and print last situation of map*/
    else if(flag == 2)
    {
        printf("You want to exit to game. Have a good day:)\n\n");
        /*from first line-colum value to last ones take character from array and prints*/
        for(i = 0;i<forest->height;i++)
        {
            for(j=0;j<forest->width;j++)
            {
                /*for all numbers in array it assign relevent character to character variable*/
                if(forest->map[i][j] == TREE) character = 'T';
                else if(forest->map[i][j] == SPACE) character = ' ';
                else if(forest->map[i][j] == BOTANIST) character = 'B';
                else if(forest->map[i][j] == RARE_FLOWER) character = 'X';
                /*except last column write comma too with character*/
                /*for last column situation write just character*/
                if(j != forest->width -1) printf("%c,",character);
                else printf("%c",character);
            }
            printf("\n");/*to skip new line*/
        }
    }
}
/*taking informations of forest and botanist from file and initialize game board*/
void init_game(Forest *forest,Botanist *botanist)
{
    int current_row = 0,current_column = 0;
    int character_num,index_for_flower = 0;
    FILE *map;
    /*open file to read*/
    map = fopen("init.txt","r");
    char character;
    /*take informations of first 2 lines and assign them to relevent variables of forest and botanist*/
    fscanf(map,"%d,%d\n",&(forest->height),&(*forest).width);
    fscanf(map,"%d,%d,%d\n",botanist->coord_x,botanist->coord_y,&(*botanist).number_of_bottles);
    /*while it is not end of file taking characters*/
    while((character = fgetc(map)) != EOF)
    {
        /*if charcter is equal to comma start loop again from beginning*/
        if(character == ',')
            continue;
        /*if character is not equal to new line character*/
        else if(character != '\n')
        {
            /*according to character assign relevent number to charactenum variable*/
            /*and if it is cordinates of rare flower keep it into an array*/
            switch(character)
            {
                case 'T': character_num = TREE; break;
                case ' ': character_num = SPACE; break;
                case 'X': character_num = RARE_FLOWER;
                    forest->flower_x[index_for_flower] = current_row;
                    forest->flower_y[index_for_flower] = current_column;
                    index_for_flower++;
                    break;
                case 'B': character_num = BOTANIST; break;
                default: break;
            }
            /*keep character_num into map array*/
            forest->map[current_row][current_column] = character_num;
            current_column++;
        }
        /*for new line character increment row num and assign 0 to current column number*/
        else if(character == '\n')
        {
            current_row++;
            current_column = 0;
        }
    }
    /*close file*/
    fclose(map);
    printf("\n");
    int i = 0,j=0;/*i for row values and j for colums*/
    /*from first line-colum value to last ones takes character from array and prints*/
    for(;i<forest->height;i++)
    {
        for(j=0;j<forest->width;j++)
        {
            /*for all numbers in array it assign relevent character to character variable*/
            if(forest->map[i][j] == TREE) character = 'T';
            else if(forest->map[i][j] == SPACE) character = ' ';
            else if(forest->map[i][j] == BOTANIST) character = 'B';
            else if(forest->map[i][j] == RARE_FLOWER) character = 'X';
            /*except last column write comma too with character*/
            /*for last column situation write just character*/
            if(j != forest->width -1) printf("%c,",character);
            else printf("%c",character);
        }
        printf("\n");/*to skip new line*/
    }
}