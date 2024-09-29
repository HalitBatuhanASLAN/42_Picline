#include<stdio.h>
#include<string.h>
#define CITY_NUM 7 /*to keep city nums(because of '\0' 7)*/
#define HOSPITAL_NUM 4 /*to keep hospital number*/
#define CAPACITY 3 /*to keep each hospitals city capacity at most*/
struct Hospital
{
    char *name; /*for names of hospitals*/
    char cities_served[CAPACITY]; /*to keep cities which each hospital can serves*/
};
int is_enough(char cities[CITY_NUM],struct Hospital hospital[HOSPITAL_NUM],int hosipital_num,char covered_cities[CITY_NUM],int hospital_index,int indexis[4],int counter);
int all_covered(char cities[CITY_NUM],char covered_cities[CITY_NUM]);
int main()
{
    char cities[CITY_NUM] = {'A','B','C','D','E','F','\0'}; /*array for keeping cities*/
    int hospital_num,enough = 0,hospital_index = 0;/*to keep current index of selected hospital*/
    char covered_cities[CITY_NUM] = {'0','0','0','0','0','0'};/*arroy to keep covered cities*/
    int index,indexis[HOSPITAL_NUM];/*keeps indexis of selected hospitals on each combination*/
    int counter = 0,k;/*to keep hospital number in combination and k is for writing as indexis*/
    /*assigns name and city informations for each hospital by using struct*/
    struct Hospital hospital[HOSPITAL_NUM] = 
    { 
        {"Hospital 1",{'A','B','C'}},
        {"Hospital 2",{'A','B','D'}},
        {"Hospital 3",{'B','F'}},
        {"Hospital 4",{'C','E','F'}}
    };
    /*printing each hospital name and cities which serves*/
    printf("%s has cities %c,%c,%c\n",hospital[0].name,hospital[0].cities_served[0],hospital[0].cities_served[1],hospital[0].cities_served[2]);
    printf("%s has cities %c,%c,%c\n",hospital[1].name,hospital[1].cities_served[0],hospital[1].cities_served[1],hospital[1].cities_served[2]);
    printf("%s has cities %c,%c,%c\n",hospital[2].name,hospital[2].cities_served[0],hospital[2].cities_served[1],hospital[2].cities_served[2]);
    printf("%s has cities %c,%c,%c\n",hospital[3].name,hospital[3].cities_served[0],hospital[3].cities_served[1],hospital[3].cities_served[2]);
    printf("Enter the maximum number of hospitals that can be constructed : ");
    scanf("%d",&hospital_num);
    /*controlling hospital number is acceptable or not*/
    if(hospital_num > 4) printf("You do not have enough spacess for hospitals.You can construct at most 4 hospitals\n");
    else if(hospital_num < 1) printf("You must construct at least 1 hospital\n");
    else 
    {
        /*if return values of recursive functşon is not eual to 1 then some cities are not covered*/
        /*if return values of recursive functşon is eual to 1 then prints hospitals and cities for each hospital*/
        enough = is_enough(cities,hospital,hospital_num,covered_cities,hospital_index,indexis,counter);
        if(enough != 1) printf("Some citites are not covered\n");
        else if(enough = 1)
        {
            printf("All hospitals covered\n");
            for(index = 0;index<hospital_num;index++)
            {
                printf("%s whic cover cities : ",hospital[indexis[index]].name);
                for(k = 0;k<CAPACITY;k++)
                    printf("%c,",hospital[indexis[index]].cities_served[k]);
                printf("\n");
            }
        }
    }
}
/*recursion function to keep covered cities according to selected hospitals by combination and recursion*/
int is_enough(char cities[CITY_NUM],struct Hospital hospital[HOSPITAL_NUM],int hosipital_num,char covered_cities[CITY_NUM],int hospital_index,int indexis[4],int counter)
{
    int i = 0,j = 0,k,l,flag,return_value;
    /*if hospital num is equal to 0 than fills covered cities into an aray*/
    if(hosipital_num == 0)
    {
        for(;i<counter;i++)
        {
            for(k = 0;k<CAPACITY;k++)
            {
                /*if city was covered then break function and do not add the city into arary*/
                for(l = 0;l<CITY_NUM-1;l++)
                {
                    if(covered_cities[l] == hospital[indexis[i]].cities_served[k])
                    {
                        flag = 0; break;
                    }
                    else flag = 1;
                }
                if(flag == 1)
                {
                    covered_cities[j] = hospital[indexis[i]].cities_served[k];
                    j++;
                }
            }
        }
        return(0);
    }
    for(;hospital_index<=HOSPITAL_NUM-hosipital_num;hospital_index++)
    {
        int a;
        indexis[counter] = hospital_index;/*put current hospital index into array keeps indexis of selected hospitals*/
        /*recall function with new values*/
        return_value = is_enough(cities,hospital,hosipital_num-1,covered_cities,hospital_index+1,indexis,counter+1);
        /*if return values is 0 then controll if alla cities covered if all are covered retunr 1*/
        if(return_value == 0)
        {
            if(all_covered(cities,covered_cities) == 1)
                return(1);
        }
        /*if return values is equal to 1 then return 1*/
        else if(return_value == 1)
            return(1);
    }
}
/*function to controll if all cities are covered or not*/
int all_covered(char cities[CITY_NUM],char covered_cities[CITY_NUM])
{
    int covered = 0,counter = 0;
    int index,j;
    /*control by index index if there is a match then increment counter*/
    for(index = 0;index<CITY_NUM-1;index++);
    {
        for(j = 0;j<CITY_NUM-1;j++)
            if(cities[index] == covered_cities[j]) counter++;
    }
    /*if counter is equal to city num return 1 else returns 0*/
    if(counter == CITY_NUM-1) covered = 1;
    return(covered);
}