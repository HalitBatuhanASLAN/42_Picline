#include<stdio.h>
#include<string.h>
#define number_of_people 23 /*number of people in file*/
#define info_length 20 /*length of informations*/
#define info_number 5 /*number of inormation for each people in file*/
/*prototypes of functions*/
void printing_menu();
void initializing_info_array();
void sort_people_by_age();
void sort_people_by_branch();
void filter_people_by_branch();
void filter_people_by_profession();
/* %-8s to print strings with 8 digits length*/
int main()
{
    /*to keep informaitons which are taken from file*/
    char informations[number_of_people][info_number][info_length];
    /*for filling array with informations from file*/
    initializing_info_array(informations);
    printing_menu(informations);
}
/*printing menu and all stuffs are made in that function*/
void printing_menu(char informations[number_of_people][info_number][info_length])
{
    char choise,wanted[info_length];/*to keep wanted branch as string*/
    int i = 0;
    char character;
    do 
    {
        printf("************Menu**********\n");
        printf("1. Sort and display all individuals by age\n");
        printf("2. Sort and display individuals in the branch by age\n");
        printf("3. Show individuals with the wanted branch\n");
        printf("4. Filter people by profession\n");
        printf("5. Exit\n");
        printf("Enter your choise from menu please : ");
        scanf(" %c",&choise);
        /*according to relevant choise call the relevant function*/
        switch(choise)
        {
        case '1':
            printf("\n");
            sort_people_by_age(informations);
            break;
        case '2':
            printf("\n");
            sort_people_by_branch(informations);
            break;
        case '3':
            printf("Enter the branch which you want to search : ");
            i = 0;
            /*take input from user in case user is not entered new line character*/
            /*firstly it has previous enter character so to enter in loop added i==0 condition too*/
            while(i == 0 || character != '\n')
            {
                character = getchar();
                /*if character is new line character and index value is not 0 break loop*/
                if(character == '\n' && i != 0)
                    break;
                /*if i==0 and charcter is equal to new line character than take next character*/
                else if(character == '\n' && i == 0)
                    character = getchar();
                wanted[i] = character;
                i++;
            }
            /*to put end of string character to end of string*/
            wanted[i] = '\0';
            filter_people_by_branch(informations,wanted);
            printf("\n");
            break;
        case '4':
            printf("Enter the profession which you want to search for people who works only with that profession : ");
            i = 0;
            /*take input from user in case user is not entered new line character*/
            /*firstly it has previous enter character so to enter in loop added i==0 condition too*/
            while(i == 0 || character != '\n')
            {
                character = getchar();
                /*if character is new line character and index value is not 0 break loop*/
                if(character == '\n' && i != 0)
                    break;
                /*if i==0 and charcter is equal to new line character than take next character*/
                else if(character == '\n' && i == 0)
                    character = getchar();
                wanted[i] = character;
                i++;
            }
            /*to put end of string character to end of string*/
            wanted[i] = '\0';
            filter_people_by_profession(informations,wanted);
            printf("\n");
            break;
        case '5':
            printf("\nThanks for choosing our program.Goodbye:)\n");
            break;
        default:
            printf("!!!Please enter a valid value\n");
            break;
        }
    }
    while(choise != '5');
}
/*sorting people by their ages*/
void sort_people_by_age(char informations[number_of_people][info_number][info_length])
{
    int index[number_of_people];/*to keep index values of people*/
    int i = 0,j,tmp;
    /*keep it with index values from 0 to 22(last persons index)*/
    for(;i<number_of_people;i++)
        index[i] = i;
    /*with bubble sort algorithm compara age values with string compare function*/
    /*and if there is needed to change for ages change only index values of people not to change original array*/
    /*original array can be changed but for that function I just want to use parallel arrays to improve myself*/
    for(i = 0;i<number_of_people-1;i++)
    {
        for(j = 0;j<number_of_people-i-1;j++)
        {
            /*if next peoples ages is less than current one change their index values which is keeping in index array*/
            if(strcmp(informations[index[j]][2],informations[index[j+1]][2]) > 0)
            {
                tmp = index[j];
                index[j] = index[j+1];
                index[j+1] = tmp;
            }
        }
    }
    /*printing people by increasing of ages*/
    printf("Name\t\tSurname\t\tAge\t\tBranch1\t\tBranch2\n\n");
    for(i = 0;i<number_of_people;i++)
    {
        for(j = 0;j<info_number;j++)
            printf("%-8s\t",informations[index[i]][j]);
        printf("\n");
    }
    printf("\n");
}
/*sorting people by theri branches*/
void sort_people_by_branch(char informations[number_of_people][info_number][info_length])
{
    char tmp[info_length];/*just keeping information before changing*/
    int current_people,j,current_info;
    for(current_people = 0;current_people<number_of_people-1;current_people++)
    {
        for(j = 0;j<number_of_people-1;j++)
        {
            /*if current branc name comes after next one than change them*/
            if(strcmp(informations[j][3],informations[j+1][3]) > 0)
            {
                /*till end of informations for those 2 people change their informatins by using strcpy functions and tampurary array*/
                for(current_info = 0;current_info<info_number;current_info++)
                {
                    strcpy(tmp,informations[j][current_info]);
                    strcpy(informations[j][current_info],informations[j+1][current_info]);
                    strcpy(informations[j+1][current_info],tmp);
                }
            }
            /*if branches are same*/
            else if(strcmp(informations[j][3],informations[j+1][3]) == 0)
            {
                /*control for the second branch if second branch is comes later for current person changes their informations*/
                if(strcmp(informations[j][4],informations[j+1][4]) > 0)
                {
                    for(current_info = 0;current_info<info_number;current_info++)
                    {
                        strcpy(tmp,informations[j][current_info]);
                        strcpy(informations[j][current_info],informations[j+1][current_info]);
                        strcpy(informations[j+1][current_info],tmp);
                    }
                }
                /*if their branchse are also equal then sort them by their ages*/
                else if(strcmp(informations[j][4],informations[j+1][4]) == 0)
                {
                    /*check their ages and if needed change their informations*/
                    if(strcmp(informations[j][2],informations[j+1][2])>0)
                    {
                        for(current_info = 0;current_info<info_number;current_info++)
                        {
                            strcpy(tmp,informations[j][current_info]);
                            strcpy(informations[j][current_info],informations[j+1][current_info]);
                            strcpy(informations[j+1][current_info],tmp);
                        }
                    }
                }
            }
        }
    }
    printf("Name\t\tSurname\t\tAge\t\tBranch1\t\tBranch2\n\n");
    for(current_people= 0;current_people<number_of_people;current_people++)
    {
        for(j = 0;j<info_number;j++)
            printf("%-8s\t",informations[current_people][j]);
        printf("\n");
    }
    printf("\n");
}
/*filter people according to wanted branch*/
void filter_people_by_branch(char informations[number_of_people][info_number][info_length],char wanted[20])
{
    int current_people,current_info,i,j;
    printf("Name\t\tSurname\t\tAge\t\tBranch1\t\tBranch2\n\n");
    for(current_people = 0;current_people<number_of_people;current_people++)
    {
        /*search both information on 3'rd and 4'th indexis(4,5. columns)*/
        for(current_info = 3;current_info <= 4;current_info++)
        {
            /*till end of branch string*/
            for(i = 0;informations[current_people][current_info][i] != '\0';i++)
            {
                j = 0;
                /*if first index of wanted branch is equal to relevant index of branch*/
                if(informations[current_people][current_info][i] == wanted[j])
                {
                    j++;
                    /*in case both strings are equal and none of thm is ended*/
                    while(informations[current_people][current_info][i+j] == wanted[j] && wanted[j] != '\0' && informations[current_people][current_info][i+j] != '\0')
                    {
                        /*if there is a dispute break loop*/
                        if(wanted[j] != informations[current_people][current_info][i+j])
                            break;
                        j++;
                    }
                    /*if loop is ended than control for wanted branch is ended ot not if it is ended than there must be a matching*/
                    /*so you can write informatios of that person*/
                    if(wanted[j] == '\0')
                    {
                        for(current_info = 0;current_info<info_number;current_info++)
                            printf("%-8s\t",informations[current_people][current_info]);
                        printf("\n");
                    }
                }
            }
        }
    }
}
/*filter people only with wanted profession not having another branch*/
void filter_people_by_profession(char informations[number_of_people][info_number][info_length],char wanted[20])
{
    int current_people,current_info,i,j,controller = 0;
    printf("Name\t\tSurname\t\tAge\t\tBranch1\t\tBranch2\n\n");
    for(current_people=0;current_people<number_of_people;current_people++)
    {
        /*do searcing just for people who has only one branch so if last string information is NULL*/
        if(*informations[current_people][4] == '\0')
        {
            current_info = 3;
            /*till end of branch string*/
            for(i = 0;informations[current_people][current_info][i] != '\0';i++)
            {
                j = 0;
                /*if first index of wanted branch is equal to relevant index of branch*/
                if(informations[current_people][current_info][i] == wanted[j])
                {
                    j++;
                    /*in case both strings are equal and none of thm is ended*/
                    while(informations[current_people][current_info][i+j] == wanted[j] && wanted[j] != '\0' && informations[current_people][current_info][i+j] != '\0')
                    {
                        /*if there is a dispute break loop*/
                        if(wanted[j] != informations[current_people][current_info][i+j])
                            break;
                        j++;
                    }
                    /*if loop is ended than control for wanted branch is ended ot not if it is ended than there must be a matching*/
                    /*so you can write informatios of that person*/
                    if(wanted[j] == '\0')
                    {
                        for(current_info = 0;current_info<info_number;current_info++)
                            printf("%-8s\t",informations[current_people][current_info]);
                        printf("\n");
                    }
                }
            }
        }
    }
}
void initializing_info_array(char informations[number_of_people][info_number][info_length])
{
    FILE *infos;
    char character;
    /*open file to read*/
    infos = fopen("input1.txt","r");
    int current_info,current_people = 0,index;
    /*till end of file read file as characters*/
    for(;!feof(infos);current_people++)
    {
        character = fgetc(infos);
        /*takes informatinos for each people*/
        for(current_info = 0;!feof(infos);current_info++)
        {
            /*if characters is nor end of line character and comma then keep readining*/
            for(index = 0;character != '\n' && character != ',' && !feof(infos);index++)
            {
                informations[current_people][current_info][index] = character;
                character = fgetc(infos);
            }
            /*put end of string character after taking relevant informatin*/
            informations[current_people][current_info][index] = '\0';
            /*if it is end of line than if there is no 5 informations fill next informations as NULL*/
            /*to make last info column string as a null string*/
            if(character == '\n')
            {
                if(current_info != 4)
                    informations[current_people][current_info+1][0] = '\0';
                break;
            }
            /*take character in case of character is space.Not to keep spaceses helps on comparations of strings*/
            do
                character = fgetc(infos);
            while(character == ' ');
        }
    }
    /*close file*/
    fclose(infos);
    printf("\n");
}