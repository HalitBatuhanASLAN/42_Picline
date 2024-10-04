#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*struct to keep informations of species as a linkd list*/
typedef struct species
{
    char *class;
    char *order;
    char *family;
    char *genus;
    char *species;
    struct species *next;
}species;
/*prototypes of functions*/
void deleting_species(species *adress,char species_name[15]);
void sorting(species *adress,char criteria[15]);
void changing_info(species *adress,char species_name[15]);
struct species *adding(species *adress);
void printing_list(species *adress);
void menu();
int main()
{
    species *adress = NULL;
    int i;
    char choise,list_creteria[15],species_name[15];
    char menu_choise,character;
    /*till user enteres 'e' take informations and add them to list*/
    while(choise != 'e')
    {
        printf("\nEnter species informations;\n");
        adress = adding(adress);
        printf("If you want to exit enter 'e',to continue enter another character : ");
        scanf(" %c",&choise);
    }
    /*printing beginning situation of list*/
    printing_list(adress);
    /*till user wants to exit take choise from user and do
    the relevant choise*/
    do
    {
        menu();
        scanf(" %c",&menu_choise);
        switch(menu_choise)
        {
        case '1':
            /*case 1 to add new species to list*/
            printf("\nEnter species informations;\n");
            adress = adding(adress);
            break;
        case '2':
            /*case 2 to sort list according to criteria*/
            printf("Enter list creteria ");
            printf("(class,order,family,genus,species) : ");
            scanf("%s",list_creteria);
            sorting(adress,list_creteria);
            printf("Listted species are;\n");
            printing_list(adress);
            break;
        case '3':
            /*case 3 to modify informations of wanted species*/
            printf("Enter species information to modify :\n");
            printf("Old Species : ");
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
                species_name[i] = character;
                i++;
            }
            /*to put end of string character to end of string*/
            species_name[i] = '\0';
            changing_info(adress,species_name);
            printing_list(adress);
            break;
        case '4':
            /*case 4 to delete informations of wanted species*/
            printf("Enter species information to delete : ");
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
                species_name[i] = character;
                i++;
            }
            /*to put end of string character to end of string*/
            species_name[i] = '\0';
            deleting_species(adress,species_name);
            printing_list(adress);
            break;
        case '5':
            /*case 5 to printing list*/
            printing_list(adress);
            break;
        case '0':
            /*to exit program*/
            printf("    Thanks for choosing our program\n");
            printf("    Have a good day\n");
            break;
        default:
            /*for controlling of default values*/
            printf("!!! Enter a valid input\n");
            break;
        }
    }
    while(menu_choise != '0');
    species *tmp;
    /*till end of free spaces which allocated*/
    while(adress != NULL)
    {
        tmp = adress;
        adress = adress->next;
        free(tmp->class);
        free(tmp->order);
        free(tmp->family);
        free(tmp->genus);
        free(tmp->species);
        free(tmp);
    }
    return(0);
}
/*to delete species with gicen species name*/
void deleting_species(species *adress,char species_name[15])
{
    species *tmp = adress;
    species *previous = NULL;
    /*till end of species*/
    while(tmp)
    {
        /*if there is maetch between species*/
        if(strcmp(tmp->species,species_name) == 0)
        {
            /*if user want to delete first one*/
            if(previous == NULL && tmp->next != NULL)
            {
                struct species *new_adress = tmp->next;
                *adress = *new_adress;
            }
            /*if there is only one*/
            else if(previous == NULL && tmp->next == NULL)
                adress->class = NULL;
            else
                previous->next = tmp->next;
            return;
        }
        previous = tmp;
        tmp = tmp->next;
    }
    printf("!!! There is no any species with entered one\n\n");
}
/*to sort list as the given criteria value*/
void sorting(species *adress,char criteria[15])
{
    species *tmp = (species *)malloc(sizeof(species));
    species *current = adress;
    /*allocations to keep informations of the changing ones*/
    species *changing_info = (species *)malloc(sizeof(species));
    changing_info->class = (char *)calloc(sizeof(char),20);
    changing_info->family = (char *)calloc(sizeof(char),20);
    changing_info->order = (char *)calloc(sizeof(char),20);
    changing_info->genus = (char *)calloc(sizeof(char),20);
    changing_info->species = (char *)calloc(sizeof(char),20);
    tmp = current;
    int i,j,counter;
    /*printf("The criteria which you want to sort is : %s\n",criteria);*/
    /*by using bubble sort sort informations*/
    for(;current != NULL;current = current->next)
    {
        for(tmp = current->next;tmp != NULL;tmp = tmp->next)
        {
            /*control for correct sorting criteria*/
            if(strcmp(criteria,"class") == 0)
            {
                /*printf("changing according to class values\n");*/
                /*if return result of strcmp func is bigger than 0
                than as ascii values you need to change informations*/
                if(strcmp(current->class,tmp->class) > 0)
                {
                    /*copy currents informations to another species struct
                    and than copy next ones informatins to current one and
                    copy changing informations to next one*/
                    strcpy(changing_info->class,current->class);
                    strcpy(current->class,tmp->class);
                    strcpy(tmp->class,changing_info->class);
                    
                    strcpy(changing_info->family,current->family);
                    strcpy(current->family,tmp->family);
                    strcpy(tmp->family,changing_info->family);
                    
                    strcpy(changing_info->order,current->order);
                    strcpy(current->order,tmp->order);
                    strcpy(tmp->order,changing_info->order);
                    
                    strcpy(changing_info->genus,current->genus);
                    strcpy(current->genus,tmp->genus);
                    strcpy(tmp->genus,changing_info->genus);
                    
                    strcpy(changing_info->species,current->species);
                    strcpy(current->species,tmp->species);
                    strcpy(tmp->species,changing_info->species);
                }
            }
            else if(strcmp(criteria,"family") == 0)
            {
                /*printf("changing according to family values\n");*/
                if(strcmp(current->family,tmp->family) > 0)
                {
                    strcpy(changing_info->class,current->class);
                    strcpy(current->class,tmp->class);
                    strcpy(tmp->class,changing_info->class);
                    
                    strcpy(changing_info->family,current->family);
                    strcpy(current->family,tmp->family);
                    strcpy(tmp->family,changing_info->family);
                    
                    strcpy(changing_info->order,current->order);
                    strcpy(current->order,tmp->order);
                    strcpy(tmp->order,changing_info->order);
                    
                    strcpy(changing_info->genus,current->genus);
                    strcpy(current->genus,tmp->genus);
                    strcpy(tmp->genus,changing_info->genus);
                    
                    strcpy(changing_info->species,current->species);
                    strcpy(current->species,tmp->species);
                    strcpy(tmp->species,changing_info->species);
                }
            }
            else if(strcmp(criteria,"order") == 0)
            {
                /*printf("changing according to order values\n");*/
                if(strcmp(current->order,tmp->order) > 0)
                {
                    strcpy(changing_info->class,current->class);
                    strcpy(current->class,tmp->class);
                    strcpy(tmp->class,changing_info->class);
                    
                    strcpy(changing_info->family,current->family);
                    strcpy(current->family,tmp->family);
                    strcpy(tmp->family,changing_info->family);
                    
                    strcpy(changing_info->order,current->order);
                    strcpy(current->order,tmp->order);
                    strcpy(tmp->order,changing_info->order);
                    
                    strcpy(changing_info->genus,current->genus);
                    strcpy(current->genus,tmp->genus);
                    strcpy(tmp->genus,changing_info->genus);
                    
                    strcpy(changing_info->species,current->species);
                    strcpy(current->species,tmp->species);
                    strcpy(tmp->species,changing_info->species);
                }
            }
            else if(strcmp(criteria,"genus") == 0)
            {
                /*printf("changing according to genus values\n");*/
                if(strcmp(current->genus,tmp->genus) > 0)
                {
                    strcpy(changing_info->class,current->class);
                    strcpy(current->class,tmp->class);
                    strcpy(tmp->class,changing_info->class);
                    
                    strcpy(changing_info->family,current->family);
                    strcpy(current->family,tmp->family);
                    strcpy(tmp->family,changing_info->family);
                    
                    strcpy(changing_info->order,current->order);
                    strcpy(current->order,tmp->order);
                    strcpy(tmp->order,changing_info->order);
                    
                    strcpy(changing_info->genus,current->genus);
                    strcpy(current->genus,tmp->genus);
                    strcpy(tmp->genus,changing_info->genus);
                    
                    strcpy(changing_info->species,current->species);
                    strcpy(current->species,tmp->species);
                    strcpy(tmp->species,changing_info->species);
                }
            }
            else if(strcmp(criteria,"species") == 0)
            {
                /*printf("changing according to species values\n");*/
                if(strcmp(current->species,tmp->species) > 0)
                {
                    strcpy(changing_info->class,current->class);
                    strcpy(current->class,tmp->class);
                    strcpy(tmp->class,changing_info->class);
                    
                    strcpy(changing_info->family,current->family);
                    strcpy(current->family,tmp->family);
                    strcpy(tmp->family,changing_info->family);
                    
                    strcpy(changing_info->order,current->order);
                    strcpy(current->order,tmp->order);
                    strcpy(tmp->order,changing_info->order);
                    
                    strcpy(changing_info->genus,current->genus);
                    strcpy(current->genus,tmp->genus);
                    strcpy(tmp->genus,changing_info->genus);
                    
                    strcpy(changing_info->species,current->species);
                    strcpy(current->species,tmp->species);
                    strcpy(tmp->species,changing_info->species);
                }
            }
            /*if there is no any match with entered criteria give a
            error message*/
            else
            {
                printf("!!! It is not a accepted criteria\n\n");
                return;
            }
        }
    }
    /*free the spaces which you allocate for keeping informations*/
    free(changing_info->class);
    free(changing_info->family);
    free(changing_info->genus);
    free(changing_info->order);
    free(changing_info->species);
    free(changing_info);
    free(tmp);
}
/*tp change informations of a species*/
void changing_info(species *adress,char species_name[15])
{
    species *tmp = adress;
    /*to keep informations of species*/
    int i;
    char character;
    char info_array[15];
    species *previous = (species *)malloc(sizeof(species));;
    /*alocation to keep new informations of species*/
    species *new = (species *)malloc(sizeof(species));
    new->class = (char *)calloc(20,sizeof(char));
    new->family = (char *)calloc(20,sizeof(char));
    new->order = (char *)calloc(20,sizeof(char));
    new->genus = (char *)calloc(20,sizeof(char));
    new->species = (char *)calloc(20,sizeof(char));
    /*assigning new informations to species struct*/
    printf("New Class : ");
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
        info_array[i] = character;
        i++;
    }
    /*to put end of string character to end of string*/
    info_array[i] = '\0';
    strcpy(new->class,info_array);
    /*printf("%s is class\n",new->class);*/
    printf("New Order : ");
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
        info_array[i] = character;
        i++;
    }
    /*to put end of string character to end of string*/
    info_array[i] = '\0';
    strcpy(new->order,info_array);
    /*printf("%s is order\n",new->order);*/
    printf("New Family : ");
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
        info_array[i] = character;
        i++;
    }
    /*to put end of string character to end of string*/
    info_array[i] = '\0';
    strcpy(new->family,info_array);
    /*printf("%s is family\n",new->family);*/
    printf("New Genus : ");
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
        info_array[i] = character;
        i++;
    }
    /*to put end of string character to end of string*/
    info_array[i] = '\0';
    strcpy(new->genus,info_array);
    /*printf("%s is genus\n",new->genus);*/
    printf("New Species : ");
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
        info_array[i] = character;
        i++;
    }
    /*to put end of string character to end of string*/
    info_array[i] = '\0';
    strcpy(new->species,info_array);
    /*printf("%s is species\n",new->species);*/
    previous = NULL;
    /*till end of list search for correct species*/
    while(tmp != NULL)
    {
        if(strcmp(species_name,tmp->species) == 0)
        {
            printf("There is a species with entered one\n");
            new->next = tmp->next;
            /*if the changing one is head of list assign adress of new
            struct to main list by that way deleting changing first informations
            of species*/
            if(previous == NULL)
                *adress = *new;
            /*else assign new list instead of previous one*/
            else
                previous->next = new;
            printf("Values are modified\n\n");
            return;
        }
        /*going to next one*/
        previous = tmp;
        tmp = tmp->next;
    }
    /*if there is no any species with gicen one give error message*/
    printf("!!! There is no any species with entered one\n\n");
}
/*to add new species to list*/
struct species *adding(species *adress)
{
    /*array to take informations*/
    int i;
    char character;
    char info_array[15];
    /*allocating a space to keep values of species as a species struct*/
    species *tmp = (species *)malloc(sizeof(species));
    /*allocation memories for informations*/
    tmp->class = (char *)calloc(20,sizeof(char));
    tmp->family = (char *)calloc(20,sizeof(char));
    tmp->order = (char *)calloc(20,sizeof(char));
    tmp->genus = (char *)calloc(20,sizeof(char));
    tmp->species = (char *)calloc(20,sizeof(char));
    /*taking informations and assign them to relevant position in struct*/
    printf("Class : ");
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
        info_array[i] = character;
        i++;
    }
    /*to put end of string character to end of string*/
    info_array[i] = '\0';
    strcpy(tmp->class,info_array);
    /*printf("%s is class\n",tmp->class);*/
    printf("Order : ");
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
        info_array[i] = character;
        i++;
    }
    /*to put end of string character to end of string*/
    info_array[i] = '\0';
    strcpy(tmp->order,info_array);
    /*printf("%s is order\n",tmp->order);*/
    printf("Family : ");
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
        info_array[i] = character;
        i++;
    }
    /*to put end of string character to end of string*/
    info_array[i] = '\0';
    strcpy(tmp->family,info_array);
    /*printf("%s is family\n",tmp->family);*/
    printf("Genus : ");
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
        info_array[i] = character;
        i++;
    }
    /*to put end of string character to end of string*/
    info_array[i] = '\0';
    strcpy(tmp->genus,info_array);
    /*printf("%s is genus\n",tmp->genus);*/
    printf("Species : ");
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
        info_array[i] = character;
        i++;
    }
    /*to put end of string character to end of string*/
    info_array[i] = '\0';
    strcpy(tmp->species,info_array);
    /*printf("%s is species\n",tmp->species);*/
    tmp->next = NULL;
    /*if it is the first species free adress and return tmp as head of list*/
    if(adress == NULL)
    {
        free(adress);
        return(tmp);
    }
    /*else till end of list go by using another species struct and
    when it is end of list add new node to the list and return adress*/
    else
    {
        species *current = adress;
        while(current->next) current = current->next;
        current->next = tmp;
    }
    return(adress);
}
/*printing list*/
void printing_list(species *adress)
{
    species *tmp = adress;
    /*if there is no any species*/
    if(tmp->class == NULL)
        printf("You do not have any species.\n");
    else
    {
        printf("\n  The last situation of list;\n");
        /*till end of species*/
        while(tmp != NULL)
        {
            printf("Class: %s\n",tmp->class);
            printf("Order: %s\n",tmp->order);
            printf("Family: %s\n",tmp->family);
            printf("Genus: %s\n",tmp->genus);
            printf("Species: %s\n\n",tmp->species);
            tmp = tmp->next;
        }
    }
}
/*menu function to print menu*/
void menu()
{
    printf("\n------    MENU                                                  ------\n");
    printf("------    Enter (1) for adding new species to list              ------\n");
    printf("------    Enter (2) for listing addording to selected criteria  ------\n");
    printf("------    Enter (3) for modifying informations                  ------\n");
    printf("------    Enter (4) for deleting informations                   ------\n");
    printf("------    Enter (5) for printintg list                          ------\n");
    printf("------    Enter (0) for exit                                    ------\n\n");
    printf("Enter your option : ");
}