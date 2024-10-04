#include "custom_dict.h" /*including header file to be able to use functions */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void menu();/*prototype of void function*/
int main()
{
   struct Custom_dict *dictionary;/*for dictionar*/
   char *key = (char *)malloc(sizeof(char)*25);/*for key values*/
   char *data_type = (char *)malloc(sizeof(char)*10);/*for data type values*/
   Value *new_value;/*to keep values of items*/
   int field,counter;
   char file_name[15];
   dictionary = create_dict();/*firstly creating dictionary*/
   char choise;
   do
   {
      /*printing menu and taking choise of user till user enters (0)*/
      menu();
      printf("Your choise : ");
      scanf(" %c",&choise);
      switch(choise)
      {
      case '1':
         /*taking key,data tyoe and number of values of new item*/
         printf("Enter the key : ");
         scanf("%s",key);
         printf("Enter the data type of item : ");
         scanf("%s",data_type);
         printf("How many value do you enter : ");
         scanf("%d",&field);
         /*crating new area for values*/
         new_value = (Value *)malloc(sizeof(Value)*field);
         /*taking values of key from user*/
         for(counter = 0;counter<field;counter++)
         {
            if(strcmp(data_type,"int") == 0)
            {
               printf("Enter the %d. integer value : ",counter+1);
               scanf("%d",&new_value[counter].int_value);
            }
            if(strcmp(data_type,"double") == 0)
            {
               printf("Enter the %d. double value : ",counter+1);
               scanf("%lf",&new_value[counter].double_value);
            }
            if(strcmp(data_type,"float") == 0)
            {
               printf("Enter the %d. float value : ",counter+1);
               scanf("%f",&new_value[counter].float_value);
            }
            if(strcmp(data_type,"char") == 0)
            {
               printf("Enter the %d. char value : ",counter+1);
               scanf(" %c",&new_value[counter].char_values);
            }
         }
         /*sending informations of new item to add item into dictionary*/
         add_item(dictionary,key,new_value,data_type,field);
         break;
      case '2':
         /*taking key value and deletes all informations of key*/
         printf("Enter the key which you want to delete : ");
         scanf("%s",key);
         delete_items(dictionary,key);
         break;
      case '3':
         /*taking key,data tyoe and number of values of new item*/
         printf("Enter the key which you want to change values : ");
         scanf("%s",key);
         printf("Enter the data type of item : ");
         scanf("%s",data_type);
         printf("How many value do you enter : ");
         scanf("%d",&field);
         /*creat,ng values for changing values*/
         new_value = (Value *)malloc(sizeof(Value)*field);
         for(counter = 0;counter<field;counter++)
         {
            if(strcmp(data_type,"int") == 0)
            {
               printf("Enter the %d. integer value : ",counter+1);
               scanf("%d",&new_value[counter].int_value);
            }
            if(strcmp(data_type,"double") == 0)
            {
               printf("Enter the %d. double value : ",counter+1);
               scanf("%lf",&new_value[counter].double_value);
            }
            if(strcmp(data_type,"float") == 0)
            {
               printf("Enter the %d. float value : ",counter+1);
               scanf("%f",&new_value[counter].float_value);
            }
            if(strcmp(data_type,"char") == 0)
            {
               printf("Enter the %d. char value : ",counter+1);
               scanf(" %c",&new_value[counter].char_values);
            }
         }
         /*sending new values to functions to set values*/
         set_value(dictionary,key,new_value,data_type,field);
         break;
      case '4':
         /*taking key to search item and prints values of that item*/
         int i,j;
         printf("Enter key to search : ");
         scanf("%s",key);
         new_value = search_item(dictionary,key);
         if(new_value == NULL)
            printf("Key is not in the dictinary\n");
         else
         {
            printf("Values of key;\n");
            for(i = 0;i<dictionary->curent_size;i++)
            {
               if(strcmp(dictionary->items[i].key,key) == 0)
               {
                  for(j = 0;j<dictionary->items[i].field;j++)
                  {
                     if(strcmp(dictionary->items[i].data_type, "int") == 0)
                        printf("%d,",new_value[j].int_value);
                     if(strcmp(dictionary->items[i].data_type, "double") == 0)
                        printf("%.2lf,",new_value[j].double_value);
                     if(strcmp(dictionary->items[i].data_type, "float") == 0)
                        printf("%.2f,",new_value[j].float_value);
                     if(strcmp(dictionary->items[i].data_type, "char") == 0)
                        printf("%c,",new_value[j].char_values);
                  }
               }
            }
         }
         break;
      case '5':
         /*sorting dictioanry and prints new situation of dictioanry*/
         sort_dict(dictionary);
         printf("After sorting;\n");
         print_dict(dictionary);
         break;
      case '6':
         /*printing dictionary*/
         print_dict(dictionary);
         break;
      case '7':
         /*taking file name and creating dictionary*/
         printf("Enter the file name with (.csv) extension : ");
         scanf("%s",file_name);
         if(read_csv(dictionary,file_name)) printf("File opened successfully\n");
         else printf("File could not opened successfully\n");
         break;
      case '0':
         printf("Thanks for choosing our program for your issiues\n");
         printf(":) Have a good day\n");
         break;
      default:
         printf("!!!Please enter a valid value\n");
         break;
      }
   }
   while(choise != '0');
   /*free speaces which allocated for issues*/
   free_dict(dictionary);
   free(key);
   free(data_type);
}
/*printing menu function*/
void menu()
{
   printf("\n----------MENU-----------\n");
   printf("Enter (1) for adding item\n");
   printf("Enter (2) for deleting item\n");
   printf("Enter (3) for setting value\n");
   printf("Enter (4) for searching item\n");
   printf("Enter (5) for sorting dictionary\n");
   printf("Enter (6) for printing dictionary\n");
   printf("Enter (7) for readining csv file\n");
   printf("Enter (0) to exit\n");
}