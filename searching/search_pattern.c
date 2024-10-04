#include<stdio.h>
#include<string.h>
#define ROWS 100 /*max row number*/
#define MAX_COLUMNS 100 /*max column number*/
/*prototypes of functions*/
int taking_from_file(char pattern[ROWS][MAX_COLUMNS],int total_number);
void search_p1(char strs[][MAX_COLUMNS], int num_rows, int matches[][2], int * num_matches);
void search_p2(char strs[][MAX_COLUMNS], int num_rows, int matches[][2], int * num_matches);
void search_p3(char strs[][MAX_COLUMNS], int num_rows, int matches[][2], int * num_matches);
int main()
{
    char pattern[ROWS][MAX_COLUMNS];/*array for keeping pattern*/
    int num_rows = 0;
    num_rows = taking_from_file(pattern,num_rows);/*for filling pattern array*/
    int i = 0,j=0,num_matches = 0;
    int matches[ROWS][2];/*to keep matching positions*/
    /*print pattern which you take from file*/
    printf("Pattern in file \n\n");
    for(;i<num_rows;i++)
    {
        for(j = 0;j<MAX_COLUMNS; j++)
            printf("%c",pattern[i][j]);
        printf("\n");
    }
    /*for each searching pattern use relevant function than write if there is a matching point*/
    search_p1(pattern,num_rows,matches,&num_matches);
    printf("\n");
    for(i = 0;i<num_matches;i++)
        printf("P1 @ (%d,%d)\n",matches[i][0],matches[i][1]);
    num_matches = 0;/*to start with zero for each searching pattern*/
    search_p2(pattern,num_rows,matches,&num_matches);
    printf("\n");
    for(i = 0;i<num_matches;i++)
        printf("P2 @ (%d,%d)\n",matches[i][0],matches[i][1]);
    num_matches = 0;/*to start with zero for each searching pattern*/
    search_p3(pattern,num_rows,matches,&num_matches);
    printf("\n");
    for(i = 0;i<num_matches;i++)
        printf("P3 @ (%d,%d)\n",matches[i][0],matches[i][1]);
}
void search_p1(char strs[][MAX_COLUMNS], int num_rows, int matches[][2], int * num_matches)
{
    /*wanted pattern*/
    char row_pattern[] = "***++++***++++***";
    int current_line,current_column,j;
    /*start searcing from first line column combinations to last one*/
    for(current_line = 0;num_rows>current_line;current_line++)
    {
        for(current_column = 0;current_column<MAX_COLUMNS;current_column++)
        {
            /*in case it is not reached end of arrays and character in next column is same with next character in wanted pattern*/
            for(j = 0;strs[current_line][current_column+j] == row_pattern[j] && row_pattern[j] != '\0' && strs[current_line][current_column+j] != '\0';j++);
            /*if wanted array is finished and for loop ended for that then you find the pattern*/
            if(row_pattern[j] == '\0')
            {
                matches[*num_matches][0] = current_line+1;/*for line number not index number*/
                matches[*num_matches][1] = current_column+1;/*for column number not index number*/
                (*num_matches)++;/*increment number of matches*/
            }
        }
    }
}
void search_p2(char strs[][MAX_COLUMNS], int num_rows, int matches[][2], int * num_matches)
{
    /*wanted pattern*/
    char column_pattern[] = "+*+*+";
    int current_line,current_column,j;
    /*start searcing from first line column to last ones*/
    for(current_line = 0;num_rows>current_line;current_line++)
    {
        for(current_column = 0;current_column<MAX_COLUMNS;current_column++)
        {
            /*in case it is not reached end of arrays and character in next line is same with next character in wanted array*/
            for(j = 0;strs[current_line+j][current_column] == column_pattern[j] && column_pattern[j] != '\0' && strs[current_line+j][current_column] != '\0';j++);
            /*if wanted array is finished and for loop ended for that then you find the pattern*/
            if(column_pattern[j] == '\0')
            {
                matches[*num_matches][0] = current_line+1;/*for line number not index number*/
                matches[*num_matches][1] = current_column+1;/*for column number not index number*/
                (*num_matches)++;/*increment number of matches*/
            }
        }
    }
}
/*searching for pattern as diagonal*/
void search_p3(char strs[][MAX_COLUMNS], int num_rows, int matches[][2], int * num_matches)
{
    /*wanted pattern*/
    char diagonal_pattern[] = "+**+++****+++**+" ;
    int current_line,current_column,j;
    /*start searcing from first line column combinations to last ones*/
    for(current_line = 0;num_rows>current_line;current_line++)
    {
        for(current_column = 0;current_column<MAX_COLUMNS;current_column++)
        {
            /*if lower right cross is equal to new character in wanted pattern and both arrays is not reached the ends*/
            for(j = 0;strs[current_line+j][current_column+j] == diagonal_pattern[j] && diagonal_pattern[j] != '\0' && strs[current_line+j][current_column+j] != '\0';j++);
            /*if wanted array is finished and for loop ended for that then you find the pattern*/
            if(diagonal_pattern[j] == '\0')
            {
                matches[*num_matches][0] = current_line+1;/*for line number not index number*/
                matches[*num_matches][1] = current_column+1;/*for column number not index number*/
                (*num_matches)++;/*inrement number of matches*/
            }
            /*if lower left cross is equal to new character in wanted pattern and both arrays is not reached the ends*/
            for(j = 0;strs[current_line+j][current_column-j] == diagonal_pattern[j] && diagonal_pattern[j] != '\0' && strs[current_line+j][current_column-j] != '\0';j++);
            /*if wanted array is finished and for loop ended for that then you find the pattern*/
            if(diagonal_pattern[j] == '\0')
            {
                matches[*num_matches][0] = current_line+1;/*for line number not index number*/
                matches[*num_matches][1] = current_column+1;/*for column number not index number*/
                (*num_matches)++;/*inrement number of matches*/
            }
        }
    }
}
/*taking pattern from file*/
int taking_from_file(char pattern[ROWS][MAX_COLUMNS],int total_lines)
{
    int current_line = 0,current_column = 0;
    char character;
    FILE *info = fopen("input2.txt","r");/*open file for readining*/
    /*till end of file, read pattern as characters*/
    while((character = fgetc(info)) != EOF)
    {
        /*if character is new line character than add NULL character end of string*/
        /*increment line value and take column value to starting position index*/
        if(character == '\n')
        {
            pattern[current_line][current_column] = '\0';
            current_line++;
            current_column = 0;
        }
        /*for other situations*/
        else
        {
            /*if it is not reached max column number put character into the array for pattern*/
            if(current_column<MAX_COLUMNS)
            {
                pattern[current_line][current_column] = character;
                current_column++;
            }
        }
    }
    /*cloese file*/
    fclose(info);
    total_lines = current_line+1;/*to keep it as line number not last index of line*/
    return(total_lines);
}