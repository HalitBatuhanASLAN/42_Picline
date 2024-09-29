#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "custom_dict.h"
struct Custom_dict *create_dict()
{
    /*creating dictinary struct and assing null for beginnig*/
    /*allocates space for dictioanry*/
    Custom_dict *dictionary = NULL;
    dictionary = (Custom_dict *)malloc(sizeof(Custom_dict));
    /*it there is a problem in the process of allocation gives error message*/
    if(!dictionary)
        printf("Allocation space could not happen successfully\n");
    /*else assing initial values for capacity and size as 0 and return dictioanry*/
    else
    {
        dictionary->current_capacity = 0;
        dictionary->curent_size = 0;
        printf("Allocation space happeedn successfully\n");        
        return(dictionary);
    }
}
void add_item(Custom_dict *dict,char *key,Value *value,char *data_type,int field)
{
    int index,flag = 0,sub_index = 0,type;
    /*if dictionary is empty then allocate spaces for items and values structers*/
    if(dict->curent_size == 0)
    {
        Item *item_ptr = (Item *)malloc(sizeof(Item));
        Value *value_ptr = (Value *)malloc(sizeof(Value));
        dict->items = item_ptr;
        dict->items->value = value_ptr;
    }
    /*control if item haas already in dict or not if it is in then change values*/
    for(index = 0;index<dict->curent_size && flag == 0;index++)
    {
        if(strcmp(dict->items[index].key,key) == 0)
        {
            dict->items[index].data_type = data_type;
            dict->items[index].value = value;
            dict->items[index].field = field;
            flag = 1;
        }
    }
    /*if key is not in dicitonary then*/
    if(flag == 0)
    {
        /*if capacity is not enough then increment it*/
        if(dict->curent_size == dict->current_capacity)
        {
            /*allocate spaces for key,data type and values of new item*/
            /*keep neew informations into these tmp values*/
            char *tmp = (char *)malloc(sizeof(key));
            strcpy(tmp,key);
            char *tmp2 = (char *)malloc(sizeof(data_type));
            strcpy(tmp2,data_type);
            Value *tmp3 = (Value *)malloc(sizeof(value)*10);
            tmp3 = value;
            /*printf("adding values\n");*/
            /*increment capacity*/
            dict->current_capacity++;
            /*arrange spaces for new items by using realloc*/
            dict->items = (Item *)realloc(dict->items,(sizeof(Item)*dict->current_capacity));
            dict->items->data_type = (char *)realloc(dict->items->data_type,(sizeof(char)*sizeof(data_type)));
            dict->items->key = (char *)realloc(dict->items->key,(sizeof(char)*sizeof(key)));
            /*printf("realloc of item\n");
            printf("New key is %s\n",key);*/
            /*assign new key,data type and field values into last index*/
            dict->items[dict->curent_size].key = tmp;
            dict->items[dict->curent_size].data_type = tmp2;
            /*printf("data type is %s\n",data_type);
            printf("%d is filed\n",field);*/
            dict->items[index].field = field;
            /*printf("%d is filed in dictionary\n",dict->items[index].field);*/
            dict->items[index].value = tmp3;
            printf("Capacity has updated\n");
        }
        /*printf("Key is %s\n",dict->items[dict->curent_size].key);*/
        dict->curent_size++;
    }
}
void delete_items(Custom_dict *dict,char *key)
{
    int index = 0;
    /*till end of dictionary*/
    while(index < dict->curent_size)
    {
        /*printf("%s is deleted\n",key);
        printf("%s is current\n",dict->items[index].key);*/
        /*if you find key then assign the next indexis adress
        keeping informations of item to the current one by that way delete the wanted
        and makes new dicitonary*/
        if(strcmp(dict->items[index].key,key) == 0)
        {
            for(;index<dict->curent_size;index++)
                dict->items[index] = dict->items[index+1];
            dict->curent_size--;
            printf("Item was deleted\n");
            return;
        }
        index++;
    }
    printf("There is no any item with that key\n");
}
void set_value(Custom_dict *dict,char *key,Value *value,char *data_type,int field)
{
    int index = 0,sub_index;
    /*finding wanted key in items array*/
    while(strcmp(dict->items[index].key,key) != 0 && index<dict->curent_size)
        index++;
    /*assign new informations of item to previous ones*/
    if(strcmp(dict->items[index].key,key) == 0)
    {
        dict->items[index].data_type = data_type;
        dict->items[index].value = value;
        dict->items[index].field = field;
        printf("Values of key has updated\n");
    }
    else
        printf("Key is not in the dictionary\n");
}
union Value *search_item(Custom_dict *dict,char *key)
{
    if(dict == NULL)
    {
        printf("Dictionary is null\n");
        return(NULL);
    }
    int index = 0;
    while(index < dict->curent_size)
    {
        /*printf("Wanted key is %s\n",key);
        printf("Current key is %s\n",dict->items[index].key);*/
        if(strcmp(dict->items[index].key,key) == 0)
        {
            printf("Value of key returned\n");
            return(dict->items[index].value);
        }
        index++;
    }
    printf("Key is not in the dictionary\n");
    return(NULL);
}
void sort_dict(Custom_dict *dict)
{
    int index,j;
    struct Item tmp;/*to keep informations as item struct*/
    /*using buuble sort algorith mentality to sorting items*/
    for(index = 0;index < dict->curent_size;index++)
    {
        for(j = 0;j < dict->curent_size - 1 -index;j++)
        {
            if(strcmp(dict->items[j].key,dict->items[j+1].key) > 0)
            {
                tmp = dict->items[j];
                dict->items[j] = dict->items[j+1];
                dict->items[j+1] = tmp;
            }
        }
    }
}
void print_dict(Custom_dict *dict)
{
    int index,sub_index;
    /*printf("    %.2f ---------\n",dict->items[14].value[1].float_value);
    printf("    %.2lf ---------\n",dict->items[1].value[1].double_value);
    printf("    %c ---------\n",dict->items[2].value[1].char_values);
    printf("    %.2f ---------\n",dict->items[3].value[1].float_value);*/
    /*acccording to data types of itesm it prints the key and values of that item*/
    for(index = 0;index<dict->curent_size;index++)
    {
        if(strcmp(dict->items[index].data_type,"int") == 0)
        {
            printf("%d. key is %s and values are;\n",index+1,dict->items[index].key);
            /*printf("    %d is field value;\n",dict->items[index].field);*/
            for(sub_index = 0;sub_index < dict->items[index].field;)
                printf("%d. value = %d\n",sub_index,dict->items[index].value[sub_index++].int_value);
        }
        else if(strcmp(dict->items[index].data_type,"double") == 0)
        {
            printf("%d. key is %s and values are;\n",index+1,dict->items[index].key);
            /*printf("    %d is field value;\n",dict->items[index].field);*/
            for(sub_index = 0;sub_index < dict->items[index].field;)
                printf("%d. value = %.2lf\n",sub_index,dict->items[index].value[sub_index++].double_value);
        }
        else if(strcmp(dict->items[index].data_type,"float") == 0)
        {
            printf("%d. key is %s and values are;\n",index+1,dict->items[index].key);
            /*printf("    %d is field value;\n",dict->items[index].field);*/
            for(sub_index = 0;sub_index < dict->items[index].field;)
                printf("%d. value = %.2f\n",sub_index,dict->items[index].value[sub_index++].float_value);
        }
        else if(strcmp(dict->items[index].data_type,"char") == 0)
        {   
            printf("%d. key is %s and values are;\n",index+1,dict->items[index].key);
            /*printf("    %d is field value;\n",dict->items[index].field);*/
            for(sub_index = 0;sub_index < dict->items[index].field;)
                printf("%d. value = %c\n",sub_index,dict->items[index].value[sub_index++].char_values);
        }
        printf("\n");
    }
}
void free_dict(Custom_dict *dict)
{
    /*it frees spaces which allocated for dictionary*/
    free(dict->items->value);
    free(dict->items);
    free(dict);
}
int read_csv(Custom_dict *dict,const char *file_name)
{
    FILE *ptr = fopen(file_name,"r");
    char line[100],d_type[10],key[10],character;
    char seperator[3] = {", "};
    char *seperated_parts;
    int index,comma_counter,int_num;
    double double_num;
    float float_num;
    char char_value; 
    if(!ptr) return(0);
    /*it reads lines*/
    while(fgets(line,sizeof(line),ptr))
    {
        index = 0;
        /*after readining a line then by using strtok
        sepereate till first ', '*/
        seperated_parts = strtok(line,seperator);
        /*first seperated part is your data type*/
        strcpy(d_type,seperated_parts);
        /*printf("%s is data type\n",d_type);*/
        seperated_parts = strtok(NULL,seperator);
        /*second seperated part is your key value*/
        strcpy(key,seperated_parts);
        /*printf("%s is key\n",key);*/
        /*allocate space for keeping values*/
        Value *values = (Value *)malloc(sizeof(Value)*10);
        /*according to data types of item takes values and keep 
        it into values array and send these values ato add functino
        to add dictionary*/
        if(strcmp(d_type,"int") == 0)
        {
            /*printf("integer value controlling\n");*/
            while(seperated_parts = strtok(NULL,seperator))
            {
                sscanf(seperated_parts," %d",&int_num);
                values[index].int_value = int_num;
                /*printf("%d. number is %d\n",index+1,values[index].int_value);*/
                index++;
            }
            int k;
            /*for(k = 0;k<index;k++) printf("         %d\n",values[k].int_value);*/
            add_item(dict,key,values,d_type,index);
        }
        if(strcmp(d_type,"double") == 0)
        {
            /*printf("double value controlling\n");*/
            while(seperated_parts = strtok(NULL,seperator))
            {
                sscanf(seperated_parts," %lf",&double_num);
                values[index].double_value = double_num;
                /*printf("%d. number is %.2lf\n",index+1,values[index].double_value);*/
                index++;
            }
            int k;
            /*for(k = 0;k<index;k++) printf("         %.2lf\n",values[k].double_value);*/
            add_item(dict,key,values,d_type,index);
        }
        if(strcmp(d_type,"float") == 0)
        {
            /*printf("float value controlling\n");*/
            while(seperated_parts = strtok(NULL,seperator))
            {
                sscanf(seperated_parts," %f",&float_num);
                values[index].float_value = float_num;
                /*printf("%d. number is %.2f\n",index+1,values[index].float_value)0*/;
                index++;
            }
            int k;
            /*for(k = 0;k<index;k++) printf("         %.2f\n",values[k].float_value);*/
            add_item(dict,key,values,d_type,index);
        }
        if(strcmp(d_type,"char") == 0)
        {
            /*printf("char value controlling\n");*/
            while(seperated_parts = strtok(NULL,seperator))
            {
                sscanf(seperated_parts," %c",&char_value);
                values[index].char_values = char_value;
                /*printf("%d. character is %c\n",index+1,values[index].char_values);*/
                index++;
            }
            int k;
            /*for(k = 0;k<index;k++) printf("         %c\n",values[k].char_values);*/
            add_item(dict,key,values,d_type,index);
        }
    }
    fclose(ptr);
    /*int a,b;
    for(a = 0;a<dict->curent_size;a++)
        printf("field is %d of %d.values\n",dict->items[a].field,a+1);*/
    return(1);
}